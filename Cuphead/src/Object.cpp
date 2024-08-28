#include "pch.h"
#include "Object.hpp"

#include "InputDeviceHandler.hpp"
#include "Timer.hpp"
#include "Collider.hpp"

Object::Object( )
	: objPos_{ }
	, objScale_{ }
	, collider_{ nullptr }
{}

Object::~Object( )
{}

void Object::CreateCollider( ) {
	collider_ = new Collider{ this };
}

void Object::update( ) {
}

void Object::componentUpdate( ) {
	if ( collider_ ) {
		collider_->update( );
	}
}

void Object::render( HDC hdc )
{
	Rectangle( hdc
		, static_cast<int>( objPos_.x - objScale_.x / 2.f )
		, static_cast<int>( objPos_.y - objScale_.y / 2.f )
		, static_cast<int>( objPos_.x + objScale_.x / 2.f )
		, static_cast<int>( objPos_.y + objScale_.y / 2.f ) );

	componentRender( hdc );
}

void Object::componentRender( HDC hdc ) {
	if ( collider_ ) {
		collider_->render( hdc );
	}
}
