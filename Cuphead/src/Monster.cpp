#include "pch.h"
#include "Monster.hpp"

#include "Timer.hpp"

Monster::Monster( )
	: centerPos_{ Vec2{ 0.f, 0.f } }
	, speed_{ 100.f }
	, maxDistance_{ 100.f }
	, dir_{ 1 }
{
}

Monster::~Monster( )
{
}

void Monster::update( )
{
	auto objPos = getObjPos( );

	objPos.x += speed_ * fDT * dir_;
	auto moveDist = abs( centerPos_.x - objPos.x ) - maxDistance_;

	if ( moveDist > 0.f ) {
		dir_ *= -1;
		objPos.x += moveDist * dir_;
	}

	setObjPos( objPos );
}

void Monster::render( HDC hdc )
{
	Object::render( hdc );
}
