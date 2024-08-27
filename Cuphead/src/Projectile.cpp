#include "pch.h"
#include "Projectile.hpp"

#include "Timer.hpp"

Projectile::Projectile( )
	: theta_{ 0.f }
	, direction_{ }
{}

Projectile::~Projectile( )
{
}

void Projectile::update( )
{
	auto objPos = getObjPos( );
	
	//objPos.x += 600.f * cosf( theta_ ) * fDT;
	//objPos.y -= 600.f * sinf( theta_ ) * fDT;

	objPos.x += 600.f * direction_.x * fDT;
	objPos.y -= 600.f * direction_.y * fDT;

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
