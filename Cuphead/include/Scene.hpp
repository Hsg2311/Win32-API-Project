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

private:
	// 오브젝트를 저장 및 관리할 벡터를 그룹 개수만큼 선언
	std::vector<Object*> objList_[ static_cast<UINT>( GROUP_TYPE::EOE ) ];
	std::wstring sceneName_;
};

#endif // __SCENE_HPP