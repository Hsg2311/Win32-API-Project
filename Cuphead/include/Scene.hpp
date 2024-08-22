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
	// ������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	std::vector<Object*> objList_[ static_cast<UINT>( GROUP_TYPE::EOE ) ];
	std::wstring sceneName_;
};

#endif // __SCENE_HPP