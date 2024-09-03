#include "Object.hpp"
#include "Scene.hpp"
#include <algorithm>

Scene::Scene( )
	: objGroupList_{ }
	, sceneName_{ }
{}

Scene::~Scene( ) {
	// Scene에 등록된 Object들을 delete
	std::for_each( objGroupList_.begin( ), objGroupList_.end( ), []( auto& objs ) {
		std::for_each( objs.begin( ), objs.end( ), []( auto obj ) {
			delete obj;
		} );
	} );
}

void Scene::update( ) {
	// Scene에 등록된 Object들을 update
	auto objListCopy = objGroupList_;
	std::for_each( objListCopy.begin( ), objListCopy.end( ), []( auto& objs ) {
		std::for_each( objs.begin( ), objs.end( ), []( auto obj ) {
			if( obj->IsAlive( ) )
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
	// Scene에 등록된 Object들을 componentUpdate
	auto objListCopy = objGroupList_;
	std::for_each( objListCopy.begin( ), objListCopy.end( ), []( auto& objs ) {
		std::for_each( objs.begin( ), objs.end( ), []( auto obj ) {
			obj->componentUpdate( );
		} );
	} );
}

void Scene::render( HDC hdc ) {
	// Scene에 등록된 Object들을 render
	for ( auto& group : objGroupList_ ) {
		for ( auto iter = group.begin( ); iter != group.end( ); ) {
			if ( ( *iter )->IsAlive( ) ) {
				( *iter )->render( hdc );
				++iter;
			}
			else {
				iter = group.erase( iter );
			}
		}
	}
}
