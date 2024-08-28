#include "pch.h"
#include "SceneHandler.hpp"

#include "Start_Scene.hpp"

SceneHandler::SceneHandler( )
	: sceneList_{ }
	, currScene_{ nullptr }
{}

SceneHandler::~SceneHandler( )
{
	for ( auto& scene : sceneList_ ) {
		delete scene;
	}
}

void SceneHandler::init( )
{
	// Scene ����
	sceneList_[ static_cast<UINT>( SCENE_TYPE::START_SCENE ) ] = new Start_Scene{ };
	sceneList_[ static_cast<UINT>( SCENE_TYPE::START_SCENE ) ]->setSceneName( L"Start Scene" );

	// ���� Scene ����
	currScene_ = sceneList_[ static_cast<UINT>( SCENE_TYPE::START_SCENE ) ];
	currScene_->Entry( );
}

void SceneHandler::update( )
{
	currScene_->update( );
	currScene_->componentUpdate( );
}

void SceneHandler::render( HDC hdc )
{
	currScene_->render( hdc );
}