#ifndef __STRUCT_HPP
#define __STRUCT_HPP

struct Vec2
{
	float x;
	float y;

public:
	Vec2( )
		: x{ 0.f }
		, y{ 0.f }
	{}
	
	Vec2( float x, float y )
		: x{ x }
		, y{ y }
	{}

	Vec2( int x, int y )
		: x{ static_cast<float>( x ) }
		, y{ static_cast<float>( y ) }
	{}
};

#endif // __STRUCT_HPP