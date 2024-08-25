#ifndef __MONSTER_HPP
#define __MONSTER_HPP

#include "Object.hpp"

class Monster : public Object
{
public:
	Monster( );
	virtual ~Monster( );

public:
	void setSpeed( float speed ) { speed_ = speed; }
	void setMaxDistance( float maxDistance ) { maxDistance_ = maxDistance; }

	float getSpeed( ) const { return speed_; }

	void setCenterPos( const Vec2& centerPos ) { centerPos_ = centerPos; }

public:
	virtual void update( ) override;
	virtual void render( HDC hdc ) override;

private:
	Vec2 centerPos_;
	float speed_;
	float maxDistance_;
	int dir_;
};

#endif // __MONSTER_HPP