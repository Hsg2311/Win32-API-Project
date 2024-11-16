#include "Tool_Scene.hpp"
#include "InputDeviceHandler.hpp"

Tool_Scene::Tool_Scene( ) {
}

Tool_Scene::~Tool_Scene( ) {
}

void Tool_Scene::update( ) {
	Scene::update( );

	if ( KEY_TAP( InputData::Q ) ) {
		changeScene( SCENE_TYPE::START_SCENE );
	}
}

void Tool_Scene::entry( ) {
}

void Tool_Scene::exit( ) {
}

//void Tool_Scene::update( ) {
//}