#include "CollisionHandler.hpp"
//#include <algorithm>

#include "SceneHandler.hpp"
#include "Scene.hpp"
#include "Object.hpp"
#include <algorithm>

CollisionHandler::CollisionHandler( )
	: collisionTable_{ }
{}

CollisionHandler::~CollisionHandler( ) {}

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
		if ( lgObj == nullptr || lgObj->getCollider( ) == nullptr ) return;

		std::for_each( rhsGroup.begin( ), rhsGroup.end( ), [&]( auto rgObj ) {
			// 충돌체 보유 X or 자기 자신과 충돌
			if ( rgObj == nullptr || rgObj->getCollider( ) == nullptr || lgObj == rgObj ) return;

			// 두 충돌체 아이디를 조합
			auto combination = COLLIDER_ID{
				.lr = {
					.left = lgObj->getCollider( )->getID( ),
					.right = rgObj->getCollider( )->getID( )
				}
			};

			auto iter = collisionInfo_.find( combination.id );

			// 충돌 정보가 미등록 상태인 경우 등록(충돌하지 않음으로)
			if ( iter == collisionInfo_.end( ) ) {
				collisionInfo_.insert( { combination.id, false } );
				iter = collisionInfo_.find( combination.id );
			}

			if ( IsCollided( lgObj->getCollider( ), rgObj->getCollider( ) ) ) {
				// 현재 충돌 중이다.

				if ( iter->second ) {
					// 이전에도 충돌하고 있었다. -> 충돌 중
					lgObj->OnCollision( rgObj );
					rgObj->OnCollision( lgObj );
				}
				else {
					// 이전에는 충돌하지 않았다. -> 막 충돌된 시점
					lgObj->OnCollisionEntry( rgObj );
					rgObj->OnCollisionEntry( lgObj );
					iter->second = true;
				}
			}
			else {
				// 현재 충돌하고 있지 않다.

				if ( iter->second ) {
					// 이전에는 충돌하고 있었다. -> 충돌이 막 끝난 시점
					lgObj->OnCollisionExit( rgObj );
					rgObj->OnCollisionExit( lgObj );
					iter->second = false;
				}
			}
		} );
	} );
}

bool CollisionHandler::IsCollided( Collider* lhs, Collider* rhs ) {
	auto lPos = lhs->getFinalPos( );
	auto lScale = lhs->getScale( );

	auto rPos = rhs->getFinalPos( );
	auto rScale = rhs->getScale( );

	if ( abs( lPos.x - rPos.x ) < ( lScale.x + rScale.x ) / 2.f
		&& abs( lPos.y - rPos.y ) < ( lScale.y + rScale.y ) / 2.f ) {
		return true;
	}

	return false;
}
