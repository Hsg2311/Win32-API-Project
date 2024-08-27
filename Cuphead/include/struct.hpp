#ifndef __STRUCT_HPP
#define __STRUCT_HPP

struct Vec2
{
	float x;
	float y;

public:
	void Normalize( )
	{
		auto hypotenuse = std::hypot( x, y );

		assert( hypotenuse != 0.f );

		x /= hypotenuse;
		y /= hypotenuse;
	}

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

public:
};

#endif // __STRUCT_HPP