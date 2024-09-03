#ifndef __GLOBAL_FUNC_HPP
#define __GLOBAL_FUNC_HPP

#include "define.hpp"
#include "Object.hpp"
#include "EventHandler.hpp"

void CreateObject( GROUP_TYPE groupType, Object* object ) {
	auto event = Event{
		.eventType = EVENT_TYPE::CREATE_OBJECT,
		.wParam = static_cast<DWORD_PTR>( groupType ),
		.lParam = reinterpret_cast<DWORD_PTR>( object )
	};

	EventHandler::GetInst( ).addEvent( event );
}

void DestroyObject( Object* object ) {
	auto event = Event{
		.eventType = EVENT_TYPE::DESTROY_OBJECT,
		.lParam = reinterpret_cast<DWORD_PTR>( object )
	};

	EventHandler::GetInst( ).addEvent( event );
}

#endif // __GLOBAL_FUNC_HPP