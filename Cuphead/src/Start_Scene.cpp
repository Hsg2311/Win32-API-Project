#include "pch.h"
#include "Start_Scene.hpp"

#include "Object.hpp"

Start_Scene::Start_Scene( )
{}

Start_Scene::~Start_Scene( )
{}

void Start_Scene::Entry( )
{
	Object* obj = new Object{ };
	obj->setObjPos( Vec2{ 640.f, 384.f } );
	obj->setObjScale( Vec2{ 100.f, 100.f } );
	addObject( GROUP_TYPE::DEFAULT, obj );
}

void Start_Scene::Exit( )
{
}

//void Start_Scene::update( )
//{
//	Scene::update( );
//}
//
//void Start_Scene::render( HDC hdc )
//{
//	Scene::render( hdc );
//}
