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
		std::for_each( objs.begin( ), objs.end( ), []( auto obj ) {
			delete obj;
		} );
	} );
}

void Scene::update( )
{
	// Scene�� ��ϵ� Object���� update
	auto objListCopy = objList_;
	std::for_each( objListCopy.begin( ), objListCopy.end( ), []( auto& objs ) {
		std::for_each( objs.begin( ), objs.end( ), []( auto obj ) {
			obj->update( );
		} );
	} );

	/*for ( UINT i = 0; i < (UINT)GROUP_TYPE::EOE; ++i )
	{
		for ( size_t j = 0; j < objList_[ i ].size( ); ++j )
		{

			objList_[ i ][ j ]->update( );

		}
	}*/
}

void Scene::componentUpdate( ) {
	// Scene�� ��ϵ� Object���� componentUpdate
	auto objListCopy = objList_;
	std::for_each( objListCopy.begin( ), objListCopy.end( ), []( auto& objs ) {
		std::for_each( objs.begin( ), objs.end( ), []( auto obj ) {
			obj->componentUpdate( );
		} );
	} );
}

void Scene::render( HDC hdc )
{
	// Scene�� ��ϵ� Object���� render
	std::for_each( objList_.begin( ), objList_.end( ), [&hdc]( auto& objs ) {
		std::for_each( objs.begin( ), objs.end( ), [&hdc]( auto obj ) {
			obj->render( hdc );
		} );
	} );
}
