#include "InputDeviceHandler.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "ResourceHandler.hpp"
#include "Scene.hpp"
#include "SceneHandler.hpp"
#include "struct.hpp"
#include "Texture.hpp"
#include "Timer.hpp"

Player::Player( )
	: playerTex_{ ResourceHandler::GetInst( ).LoadTexture( L"Player_Texture", L"/texture/idle/cuphead_idle.png" ) } {
	CreateCollider( );
	getCollider( )->setScale( Vec2{ 100.f, 100.f } );
}

Player::~Player( )
{}

void Player::CreateProjectile( ) {
	auto playerPos = getObjPos( );
	playerPos.y -= getObjScale( ).y / 2.f;
	
	Projectile* projectile = new Projectile{ };
	projectile->setObjPos( playerPos );
	projectile->setObjScale( Vec2{ 30.f, 30.f } );
	projectile->setDirection( Vec2( -1.f, 7.f ) );
	
	SceneHandler::GetInst( ).getCurrScene( )->addObject( GROUP_TYPE::DEFAULT, projectile );
};

void Player::update( ) {
	Vec2 objPos = getObjPos( );

	if ( KEY_HOLD( InputData::LEFT ) ) {
		objPos.x -= 200.f * fDT;
	}
	if ( KEY_HOLD( InputData::RIGHT ) ) {
		objPos.x += 200.f * fDT;
	}
	if ( KEY_HOLD( InputData::UP) ) {
		objPos.y -= 200.f * fDT;
	}
	if ( KEY_HOLD( InputData::DOWN) ) {
		objPos.y += 200.f * fDT;
	}
	if ( KEY_TAP( InputData::Z ) ) {
		CreateProjectile( );
	}

	setObjPos( objPos );
}

void Player::render( HDC hdc ) {
	Vec2 objPos = getObjPos( );

	playerTex_->Draw( hdc, objPos );

	componentRender( hdc );
}

void Player::OnCollision( Object* other )
{
}

void Player::OnCollisionEntry( Object* other )
{
	getCollider( )->addCollisionCount( );
}

void Player::OnCollisionExit( Object* other )
{
	getCollider( )->subCollisionCount( );
}
