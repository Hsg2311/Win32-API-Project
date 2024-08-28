#ifndef __SCENE_HANDLER_HPP
#define __SCENE_HANDLER_HPP

#include "define.hpp"
#include <array>
#include <Windows.h>

class Scene;

class SceneHandler {
	SINGLETON( SceneHandler );

public:
	void init( );
	void update( );
	void render( HDC hdc );

public:
	Scene* getCurrScene( ) const { return currScene_; }

private:
	std::array<Scene*, static_cast<UINT>( SCENE_TYPE::EOE )> sceneList_;
	Scene* currScene_;
};

#endif // __SCENE_HANDLER_HPP