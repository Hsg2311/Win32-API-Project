#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "Object.hpp"

class Texture;

class Player : public Object {
public:
	Player( );
	virtual ~Player( );

public:
	virtual void update( ) override;
	virtual void render( HDC hdc ) override;

public:
	void CreateProjectile( );

public:
	virtual void OnCollision( Object* other ) override;
	virtual void OnCollisionEntry( Object* other ) override;
	virtual void OnCollisionExit( Object* other ) override;

private:
	Texture* playerTex_;
};

#endif // __PLAYER_HPP