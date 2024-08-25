#include "pch.h"
#include "Player.hpp"

#include "InputDeviceHandler.hpp"
#include "Timer.hpp"

Player::Player( )
{
}

Player::~Player( )
{
}

void Player::update( )
{
	Vec2 objPos = getObjPos( );

	if ( InputDeviceHandler::GetInst( ).getKeyState( InputData::LEFT ) == KEY_STATE::HOLD ) {
		objPos.x -= 200.f * fDT;
	}
	if ( InputDeviceHandler::GetInst( ).getKeyState( InputData::RIGHT ) == KEY_STATE::HOLD ) {
		objPos.x += 200.f * fDT;
	}
	if ( InputDeviceHandler::GetInst( ).getKeyState( InputData::UP ) == KEY_STATE::HOLD ) {
		objPos.y -= 200.f * fDT;
	}
	if ( InputDeviceHandler::GetInst( ).getKeyState( InputData::DOWN ) == KEY_STATE::HOLD ) {
		objPos.y += 200.f * fDT;
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
