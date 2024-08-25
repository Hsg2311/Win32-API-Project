#ifndef __DEFINE_HPP
#define __DEFINE_HPP

#define SINGLETON(type)	public:\
							type( const type& ) = delete;\
							type& operator=( const type& ) = delete;\
							type( type&& ) = delete;\
							type& operator=( type&& ) = delete;\
							\
							static type& GetInst()\
							{\
								static type instance;\
								return instance;\
							}\
						private:\
							type( );\
							~type( )

#define fDT Timer::GetInst().getFDT()
#define DT Timer::GetInst().getDT()

#define KEY_CHECK( key, state ) InputDeviceHandler::GetInst().getKeyState(key) == state
#define KEY_TAP( key ) KEY_CHECK( key, KEY_STATE::TAP )
#define KEY_HOLD( key ) KEY_CHECK( key, KEY_STATE::HOLD )
#define KEY_AWAY( key ) KEY_CHECK( key, KEY_STATE::AWAY )
#define KEY_NONE( key ) KEY_CHECK( key, KEY_STATE::NONE )

enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	PROJECTILE,
	ENEMY,

	EOE
};

enum class SCENE_TYPE
{
	START_SCENE,
	TUTORIAL_SCENE,

	EOE
};

#endif // __DEFINE_HPP