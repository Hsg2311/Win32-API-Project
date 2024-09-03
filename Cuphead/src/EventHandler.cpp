#include "EventHandler.hpp"
#include "Object.hpp"
#include "SceneHandler.hpp"
#include "Scene.hpp"
#include <algorithm>

EventHandler::EventHandler( ) : events_{ }, deadObjects_{ } {}

EventHandler::~EventHandler( ) {}

void EventHandler::update( ) {
	// ���� �����ӿ��� ����ص� Dead Object�� ����
	std::for_each( deadObjects_.begin( ), deadObjects_.end( ), [this]( const auto& obj ) {
		delete obj;
	} );

	deadObjects_.clear( );

	// Event ó��
	std::for_each( events_.begin( ), events_.end( ), [this]( const auto& event ) {
		excute( event );
	} );

	events_.clear( );
}

void EventHandler::excute( const Event& event ) {
	switch ( event.eventType ) {
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// wParam : Group Type
		// lParam : Object Pointer
		auto groupType = static_cast<GROUP_TYPE>( event.wParam );
		auto obj = reinterpret_cast<Object*>( event.lParam );

		SceneHandler::GetInst( ).getCurrScene( )->addObject( groupType, obj );
	}
		break;

	case EVENT_TYPE::DESTROY_OBJECT:
	{
		auto obj = reinterpret_cast<Object*>( event.lParam );
		obj->alive_ = false;
		deadObjects_.emplace_back( obj );
	}
		break;

	case EVENT_TYPE::CHANGE_SCENE:
		break;
	}
}
