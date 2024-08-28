#ifndef __COLLIDER_HPP
#define __COLLIDER_HPP

#include "Object.hpp"

class Collider
{
public:
	Collider( Object* obj ) : myObj_{ obj }, offset_{ }, finalPos_{ } {}

public:
	void update( ) {
		// Object의 위치를 따라간다.
		finalPos_ = myObj_->getObjPos( ) + offset_;
	}

	void render( HDC hdc );

public:
	void setOffset( const Vec2& offset ) { offset_ = offset; }
	void setScale( const Vec2& scale ) { scale_ = scale; }

	Vec2 getOffset( ) const { return offset_; }
	Vec2 getScale( ) const { return scale_; }

private:
	Object* myObj_;
	Vec2 offset_;
	Vec2 finalPos_;
	Vec2 scale_;
};

#endif // __COLLIDER_HPP