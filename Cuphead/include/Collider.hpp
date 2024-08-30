#ifndef __COLLIDER_HPP
#define __COLLIDER_HPP

#include "SelectGdiObject.hpp"
#include "struct.hpp"

class Collider {
public:
	Collider( ) 
		: offset_{ }
		, finalPos_{ }
		, scale_{ }
		, id_{ nextId_++ }
	{}

public:
	void setOffset( const Vec2& offset ) { offset_ = offset; }
	void setScale( const Vec2& scale ) { scale_ = scale; }

	Vec2 getOffset( ) const { return offset_; }
	Vec2 getScale( ) const { return scale_; }

public:
	void update( const Vec2 myObjPos ) {
		// Object의 위치를 따라간다.
		finalPos_ = myObjPos + offset_;
	}

	void render( HDC hdc ) {
		SelectGdiObject gdiObject{ hdc, PEN_TYPE::GREEN, BRUSH_TYPE::HOLLOW };

		Rectangle( hdc
			, static_cast<int>( finalPos_.x - scale_.x / 2.f )
			, static_cast<int>( finalPos_.y - scale_.y / 2.f )
			, static_cast<int>( finalPos_.x + scale_.x / 2.f )
			, static_cast<int>( finalPos_.y + scale_.y / 2.f ) );
	}

private:
	Vec2 offset_;
	Vec2 finalPos_;
	Vec2 scale_;
	UINT id_;

	static UINT nextId_;
};

#endif // __COLLIDER_HPP