#include "TitleScene.hpp"
#include "Background.hpp"
#include "define.hpp"

void TitleScene::update( ) {
	Scene::update( );
}

void TitleScene::entry( ) {
	auto background = new Background( L"Title", L"title_background.png" );
	background->setObjName( L"Title" );
	addObject( GROUP_TYPE::BACKGROUND, background );

	auto backgroundAnim = new BackgroundAnim( L"Title_Cuphead_and_MugMan", L"title_cuphead_Mugman.png", 0.04f, 34 );
	backgroundAnim->setObjName( L"Title_Cuphead_and_MugMan" );
	backgroundAnim->setObjPos( Vec2( 640.f, 410.f ) );
	addObject( GROUP_TYPE::BACKGROUND, backgroundAnim );
}

void TitleScene::exit( ) {
	Scene::destroyObjGroupList( );
}
