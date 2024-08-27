#ifndef __PROJECTILE_HPP
#define __PROJECTILE_HPP

#include "Object.hpp"

class Projectile : public Object
{
public:
	Projectile( );
	virtual ~Projectile( );

public:
	void setDirection( float theta ) { theta_ = theta; }

public:
	virtual void update( ) override;
	virtual void render( HDC hdc ) override;

private:
	float theta_;
};

#endif // __PROJECTILE_HPP