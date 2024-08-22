#ifndef __SCENE_HPP
#define __SCENE_HPP

class Object;

class Scene
{
public:
	Scene( );
	virtual ~Scene( ) = 0;

public:
	void setSceneName( const std::wstring& sceneName ) { sceneName_ = sceneName; }
	const std::wstring& getSceneName( ) const { return sceneName_; }

public:
	virtual void Entry( ) = 0;
	virtual void Exit( ) = 0;

	void update( );
	void render( HDC hdc );

public:
	void addObject( GROUP_TYPE groupType, Object* obj ) {
		objList_[ static_cast<UINT>( groupType ) ].emplace_back( obj );
	}

private:
	// ������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	std::array<std::vector<Object*>, static_cast<UINT>( GROUP_TYPE::EOE )> objList_;
	std::wstring sceneName_;
};

#endif // __SCENE_HPP