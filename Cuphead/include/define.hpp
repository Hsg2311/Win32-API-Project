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