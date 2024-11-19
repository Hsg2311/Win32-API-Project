#include "SceneHandler.hpp"
#include "Start_Scene.hpp"
#include "Tool_Scene.hpp"
#include "TitleScene.hpp"

SceneHandler::SceneHandler( )
	: sceneList_{ }
	, currScene_{ nullptr }
	, currSceneType_{ SCENE_TYPE::TITLE_SCENE }
{}

SceneHandler::~SceneHandler( ) {
	for ( auto& scene : sceneList_ ) {
		delete scene;
	}
}

void SceneHandler::init( ) {
	// Scene 생성
	sceneList_[ static_cast<UINT>( SCENE_TYPE::TITLE_SCENE ) ] = new TitleScene{ };
	sceneList_[ static_cast<UINT>( SCENE_TYPE::TITLE_SCENE ) ]->setSceneName( L"Title Scene" );

	sceneList_[ static_cast<UINT>( SCENE_TYPE::START_SCENE ) ] = new Start_Scene{ };
	sceneList_[ static_cast<UINT>( SCENE_TYPE::START_SCENE ) ]->setSceneName( L"Start Scene" );

	sceneList_[ static_cast<UINT>( SCENE_TYPE::TOOL_SCENE ) ] = new Tool_Scene{ };
	sceneList_[ static_cast<UINT>( SCENE_TYPE::TOOL_SCENE ) ]->setSceneName( L"Tool Scene" );

	// 현재 Scene 설정
	currScene_ = sceneList_[ static_cast<UINT>( SCENE_TYPE::TITLE_SCENE ) ];
	currSceneType_ = SCENE_TYPE::TITLE_SCENE;
	currScene_->entry( );
}
