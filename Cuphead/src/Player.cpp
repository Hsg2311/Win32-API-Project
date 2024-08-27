#include "pch.h"
#include "Player.hpp"

#include "InputDeviceHandler.hpp"
#include "Timer.hpp"

#include "Projectile.hpp"
#include "Scene.hpp"
#include "SceneHandler.hpp"

Player::Player( )
{
}

Player::~Player( )
{
}

void Player::CreateProjectile( )
{
	auto playerPos = getObjPos( );
	playerPos.y -= getObjScale( ).y / 2.f;
	
	Projectile* projectile = new Projectile{ };
	projectile->setObjPos( playerPos );
	projectile->setObjScale( Vec2{ 30.f, 30.f } );
	projectile->setDirection( M_PI_4 );
	
	SceneHandler::GetInst( ).getCurrScene( )->addObject( GROUP_TYPE::DEFAULT, projectile );
};

void Player::update( )
{
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

void Player::render( HDC hdc )
{
	Vec2 objPos = getObjPos( );
	Vec2 objScale = getObjScale( );
	
	Rectangle( hdc
		, static_cast<int>( objPos.x - objScale.x / 2.f )
		, static_cast<int>( objPos.y - objScale.y / 2.f )
		, static_cast<int>( objPos.x + objScale.x / 2.f )
		, static_cast<int>( objPos.y + objScale.y / 2.f ) );
}
