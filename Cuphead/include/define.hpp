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

inline float fDT( ) { return Timer::GetInst( ).getFDT( ); }
inline double DT( ) { return Timer::GetInst( ).getDT( ); }

#endif // __DEFINE_HPP