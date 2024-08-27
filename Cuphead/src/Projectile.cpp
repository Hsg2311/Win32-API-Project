#include "pch.h"
#include "Projectile.hpp"

#include "Timer.hpp"

Projectile::Projectile( )
	: direction_{ 0.f }
{
}

Projectile::~Projectile( )
{
}

void Projectile::update( )
{
	auto objPos = getObjPos( );

	objPos.y += 600.f * fDT * direction_;

	setObjPos( objPos );
}

void Projectile::render( HDC hdc )
{
	auto objPos = getObjPos( );
	auto objScale = getObjScale( );

	Ellipse( hdc,
		static_cast<int>( objPos.x - objScale.x / 2.f ),
		static_cast<int>( objPos.y - objScale.y / 2.f ),
		static_cast<int>( objPos.x + objScale.x / 2.f ),
		static_cast<int>( objPos.y + objScale.y / 2.f ) );
}
