#include "Start_Scene.hpp"
#include "Object.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "Core.hpp"
#include "CollisionHandler.hpp"

Start_Scene::Start_Scene( )
{}

Start_Scene::~Start_Scene( )
{}

void Start_Scene::Entry( ) {
	Object* obj = new Player{ };
	obj->setObjPos( Vec2{ 640.f, 384.f } );
	obj->setObjScale( Vec2{ 100.f, 100.f } );
	addObject( GROUP_TYPE::PLAYER, obj );

	const auto monCount = 16;
	const auto monScale = 50.f;
	const auto moveDist = 25.f;
	const auto step = ( Core::GetInst( ).getResolution( ).x - (2*moveDist+monScale) ) / (monCount - 1);

	for ( auto i = 0; i < monCount; ++i ) {
		Monster* mon = new Monster{ };
		mon->setObjPos( Vec2{ ( moveDist + monScale / 2.f ) + step * i, 50.f } );
		mon->setCenterPos( mon->getObjPos( ) );
		mon->setObjScale( Vec2{ monScale, monScale } );
		mon->setMaxDistance( moveDist );
		mon->setSpeed( 200.f );
		addObject( GROUP_TYPE::ENEMY, mon );
	}

	// 충돌 지정
	// 그룹 간의 충돌을 검사한다.
	CollisionHandler::GetInst( ).checkCollision( GROUP_TYPE::PLAYER, GROUP_TYPE::ENEMY );
}

void Start_Scene::Exit( ) {
	CollisionHandler::GetInst( ).reset( );
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
