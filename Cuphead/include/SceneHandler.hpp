#ifndef __SCENE_HANDLER_HPP
#define __SCENE_HANDLER_HPP

class Scene;

class SceneHandler
{
	SINGLETON( SceneHandler );

public:
	void init( );
	void update( );
	void render( HDC hdc );

private:
	std::array<Scene*, static_cast<UINT>( SCENE_TYPE::EOE )> sceneList_;
	Scene* currScene_;
};

#endif // __SCENE_HANDLER_HPP