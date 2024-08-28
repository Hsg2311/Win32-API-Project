#ifndef __PROJECTILE_HPP
#define __PROJECTILE_HPP

#include "Object.hpp"
#include "struct.hpp"
#include <Windows.h>

class Projectile : public Object {
public:
	Projectile( );
	virtual ~Projectile( );

public:
	void setDirection( float theta ) { theta_ = theta; }
	void setDirection( const Vec2& direction ) { 
		direction_ = direction;
		direction_.Normalize( );
	}

public:
	virtual void update( ) override;
	virtual void render( HDC hdc ) override;

private:
	float theta_;
	Vec2 direction_;
};

#endif // __PROJECTILE_HPP