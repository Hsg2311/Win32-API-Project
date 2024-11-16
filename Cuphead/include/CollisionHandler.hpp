#ifndef __COLLISION_HANDLER_HPP
#define __COLLISION_HANDLER_HPP

#include "define.hpp"
#include <array>
#include <map>

#define NOMINMAX		// Windows.h�� min, max ��ũ�θ� ������� �ʵ��� �Ѵ�.
#define LEAN_AND_MEAN	// �� ������� �ʴ� API�� �����Ѵ�.
						// �� �ΰ����� Windows.h�� include�ϱ� ���� define �ϴ� ���� ��õ�Ѵ�.
#include <Windows.h>

class Collider;

union COLLIDER_ID {
	struct {
		UINT left;
		UINT right;
	} lr;
	ULONGLONG id;
};

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
	bool isCollided( Collider* lhs, Collider* rhs );

private:
	std::array<UINT, static_cast<UINT>( GROUP_TYPE::EOE )> collisionTable_;
	std::map<ULONGLONG, bool> collisionInfo_; // �浹ü ���� ���� ������ �浹 ����, LONGLONG�� �� �浹ü�� ID���� ������ ��
};

#endif // __COLLISION_HANDLER_HPP