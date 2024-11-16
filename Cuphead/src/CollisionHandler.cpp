#include "CollisionHandler.hpp"
#include "SceneHandler.hpp"
#include "Scene.hpp"
#include "Object.hpp"
#include <ranges>
#include <algorithm>

CollisionHandler::CollisionHandler( )
	: collisionTable_{ }
	, collisionInfo_{ }
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
	// �� ���� ���� �׷� Ÿ���� ������,
	// �� ū ���� �׷� Ÿ���� ��(��Ʈ)�� ����Ѵ�.
	auto row = std::min( static_cast<UINT>( lhs ), static_cast<UINT>( rhs ) );
	auto col = std::max( static_cast<UINT>( lhs ), static_cast<UINT>( rhs ) );

	// �浹 �˻縦 ���� ��Ʈ�� �Ҵ�.
	if ( collisionTable_[ row ] & ( 1 << col ) ) {
		collisionTable_[ row ] &= ~( 1 << col );
	}
	else {
		collisionTable_[ row ] |= 1 << col;
	}
}

void CollisionHandler::collisionUpdate( GROUP_TYPE lhs, GROUP_TYPE rhs ) {
	auto currScene = SceneHandler::getInst( ).getCurrScene( );

	const auto& lhsGroup = currScene->getGroup( lhs );
	const auto& rhsGroup = currScene->getGroup( rhs );

	std::ranges::for_each( lhsGroup, [&]( auto lgObj ) {
		// �浹ü ���� X
		if ( lgObj == nullptr || lgObj->getCollider( ) == nullptr ) return;

		std::ranges::for_each( rhsGroup, [&]( auto rgObj ) {
			// �浹ü ���� X or �ڱ� �ڽŰ� �浹
			if ( rgObj == nullptr || rgObj->getCollider( ) == nullptr || lgObj == rgObj ) return;

			// �� �浹ü ���̵� ����
			auto combination = COLLIDER_ID{
				.lr = {
					.left = lgObj->getCollider( )->getID( ),
					.right = rgObj->getCollider( )->getID( )
				}
			};

			auto iter = collisionInfo_.find( combination.id );

			// �浹 ������ �̵�� ������ ��� ���(�浹���� ��������)
			if ( iter == collisionInfo_.end( ) ) {
				collisionInfo_.insert( { combination.id, false } );
				iter = collisionInfo_.find( combination.id );
			}

			if ( isCollided( lgObj->getCollider( ), rgObj->getCollider( ) ) ) {
				// ���� �浹 ���̴�.

				if ( iter->second ) {
					// �������� �浹�ϰ� �־���. -> �浹 ��

					if ( !lgObj->isAlive( ) || !rgObj->isAlive( ) ) {
						// �ٵ� �� �� �ϳ��� ���� �����̶��, �浹 ����
						lgObj->onCollisionExit( rgObj );
						rgObj->onCollisionExit( lgObj );
						iter->second = false;
					}
					else {
						lgObj->onCollision( rgObj );
						rgObj->onCollision( lgObj );
					}
				}
				else {
					// �������� �浹���� �ʾҴ�. -> �� �浹�� ����
					// �ٵ� �� �� �ϳ��� ���� �����̶��, �浹���� ���� ������ ���
					if ( lgObj->isAlive( ) && rgObj->isAlive( ) ) {
						lgObj->onCollisionEntry( rgObj );
						rgObj->onCollisionEntry( lgObj );
						iter->second = true;
					}
				}
			}
			else {
				// ���� �浹�ϰ� ���� �ʴ�.

				if ( iter->second ) {
					// �������� �浹�ϰ� �־���. -> �浹�� �� ���� ����
					lgObj->onCollisionExit( rgObj );
					rgObj->onCollisionExit( lgObj );
					iter->second = false;
				}
			}
		} );
	} );
}

bool CollisionHandler::isCollided( Collider* lhs, Collider* rhs ) {
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
