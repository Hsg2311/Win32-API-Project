#ifndef __PROJECTILE_HPP
#define __PROJECTILE_HPP

#include "Object.hpp"

class Projectile : public Object
{
public:
	Projectile( );
	virtual ~Projectile( );

public:
	void setDirection( bool up )
	{
		if( up )
			direction_ = -1.f;
		else
			direction_ = 1.f;
	}

public:
	virtual void update( ) override;
	virtual void render( HDC hdc ) override;

private:
	float direction_;
};

#endif // __PROJECTILE_HPP