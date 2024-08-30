#ifndef __COLLISION_HANDLER_HPP
#define __COLLISION_HANDLER_HPP

#include "define.hpp"
#include <array>

class Collider;

#define NOMINMAX		// Windows.h의 min, max 매크로를 사용하지 않도록 한다.
#define LEAN_AND_MEAN	// 잘 사용하지 않는 API를 제외한다.
						// 이 두가지는 Windows.h를 include하기 전에 define 하는 것을 추천한다.
#include <Windows.h>

class CollisionHandler
{
	SINGLETON( CollisionHandler );

public:
	void init( );
	void update( );
	void checkCollision( GROUP_TYPE lhs, GROUP_TYPE rhs );

	void reset( ) {
		memset( collisionTable_.data( ), 0, sizeof( UINT ) * static_cast<UINT>( GROUP_TYPE::EOE ) );
	}

private:
	void collisionUpdate( GROUP_TYPE lhs, GROUP_TYPE rhs );
	bool IsCollided( Collider* lhs, Collider* rhs );

private:
	std::array<UINT, static_cast<UINT>( GROUP_TYPE::EOE )> collisionTable_;
};

#endif // __COLLISION_HANDLER_HPP