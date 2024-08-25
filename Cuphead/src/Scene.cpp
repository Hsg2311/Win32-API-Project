#include "pch.h"
#include "Scene.hpp"

#include "Object.hpp"

Scene::Scene( )
	: objList_{ }
	, sceneName_{ }
{}

Scene::~Scene( )
{
	// Scene�� ��ϵ� Object���� delete
	std::for_each( objList_.begin( ), objList_.end( ), []( auto& objs ) {
		std::for_each( objs.begin( ), objs.end( ), []( auto& obj ) {
			delete obj;
		} );
	} );
}

void Scene::update( )
{
	// Scene�� ��ϵ� Object���� update
	std::for_each( objList_.begin( ), objList_.end( ), []( auto& objs ) {
		std::for_each( objs.begin( ), objs.end( ), []( auto& obj ) {
			obj->update( );
		} );
	} );
}

void Scene::render( HDC hdc )
{
	// Scene�� ��ϵ� Object���� render
	std::for_each( objList_.begin( ), objList_.end( ), [&hdc]( auto& objs ) {
		std::for_each( objs.begin( ), objs.end( ), [&hdc]( auto& obj ) {
			obj->render( hdc );
		} );
	} );
}