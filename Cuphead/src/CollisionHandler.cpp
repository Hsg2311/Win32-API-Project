#include "CollisionHandler.hpp"
//#include <algorithm>

#include "SceneHandler.hpp"
#include "Scene.hpp"
#include "Object.hpp"
#include <algorithm>

CollisionHandler::CollisionHandler( )
	: collisionTable_{ }
{}

CollisionHandler::~CollisionHandler( )
{}

void CollisionHandler::init( )
{
}

void CollisionHandler::update( ) {
	for ( auto row = 0; row < static_cast<UINT>( GROUP_TYPE::EOE ); ++row ) {
		for ( auto col = row; col < static_cast<UINT>( GROUP_TYPE::EOE ); ++col ) {
			if ( collisionTable_[ row ] & ( 1 << col ) ) {
				collisionUpdate(
					static_cast<GROUP_TYPE>( row ),
					static_cast<GROUP_TYPE>( col )
				);
			}
		}
	}
}

void CollisionHandler::checkCollision( GROUP_TYPE lhs, GROUP_TYPE rhs ) {
	// 더 작은 값의 그룹 타입을 행으로,
	// 더 큰 값의 그룹 타입을 열(비트)로 사용한다.
	auto row = std::min( static_cast<UINT>( lhs ), static_cast<UINT>( rhs ) );
	auto col = std::max( static_cast<UINT>( lhs ), static_cast<UINT>( rhs ) );

	// 충돌 검사를 위한 비트를 켠다.
	if ( collisionTable_[ row ] & ( 1 << col ) ) {
		collisionTable_[ row ] &= ~( 1 << col );
	}
	else {
		collisionTable_[ row ] |= 1 << col;
	}
}

void CollisionHandler::collisionUpdate( GROUP_TYPE lhs, GROUP_TYPE rhs ) {
	auto currScene = SceneHandler::GetInst( ).getCurrScene( );

	const auto& lhsGroup = currScene->getGroup( lhs );
	const auto& rhsGroup = currScene->getGroup( rhs );

	std::for_each( lhsGroup.begin( ), lhsGroup.end( ), [&]( auto lgObj ) {
		// 충돌체 보유 X
		if ( lgObj == nullptr ) return;

		std::for_each( rhsGroup.begin( ), rhsGroup.end( ), [&]( auto rgObj ) {
			// 충돌체 보유 X or 자기 자신과 충돌
			if ( rgObj == nullptr || lgObj == rgObj ) return;

			IsCollided( lgObj->getCollider( ), rgObj->getCollider( ) );
		} );
	} );
}

bool CollisionHandler::IsCollided( Collider* lhs, Collider* rhs )
{
	return false;
}
