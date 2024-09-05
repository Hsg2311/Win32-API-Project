#ifndef __GLOBAL_FUNC_HPP
#define __GLOBAL_FUNC_HPP

#include "Object.hpp"
#include "EventHandler.hpp"

#include <type_traits>
#include <ranges>
#include <algorithm>

inline void CreateObject( GROUP_TYPE groupType, Object* object ) {
	auto event = Event{
		.eventType = EVENT_TYPE::CREATE_OBJECT,
		.wParam = static_cast<DWORD_PTR>( groupType ),
		.lParam = reinterpret_cast<DWORD_PTR>( object )
	};

	EventHandler::GetInst( ).addEvent( event );
}

inline void DestroyObject( Object* object ) {
	auto event = Event{
		.eventType = EVENT_TYPE::DESTROY_OBJECT,
		.lParam = reinterpret_cast<DWORD_PTR>( object )
	};

	EventHandler::GetInst( ).addEvent( event );
}

inline void ChangeScene( SCENE_TYPE sceneType ) {
	auto event = Event{
		.eventType = EVENT_TYPE::CHANGE_SCENE,
		.wParam = static_cast<DWORD_PTR>( sceneType )
	};

	EventHandler::GetInst( ).addEvent( event );
}

template<class T>
	requires std::is_pointer_v< std::remove_cvref_t<T> >
void Safe_Delete_Vector( std::vector<T>& vec ) {
	std::ranges::for_each( vec, []( auto elem ) {
		delete elem;
	} );

	vec.clear( );
}

#endif // __GLOBAL_FUNC_HPP