#include "pch.h"
#include "Object.hpp"

#include "InputDeviceHandler.hpp"
#include "Timer.hpp"

Object::Object( )
	: objPos_{ }
	, objScale_{ }
{}

Object::~Object( )
{}

void Object::update( )
{
	
}

void Object::render( HDC hdc )
{
	Rectangle( hdc
		, static_cast<int>( objPos_.x - objScale_.x / 2.f )
		, static_cast<int>( objPos_.y - objScale_.y / 2.f )
		, static_cast<int>( objPos_.x + objScale_.x / 2.f )
		, static_cast<int>( objPos_.y + objScale_.y / 2.f ) );
}
