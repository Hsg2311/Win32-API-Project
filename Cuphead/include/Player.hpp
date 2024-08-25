#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "Object.hpp"

class Player : public Object
{
public:
	Player( );
	virtual ~Player( );

public:
	virtual void update( ) override;
	virtual void render( HDC hdc ) override;
};

#endif // __PLAYER_HPP