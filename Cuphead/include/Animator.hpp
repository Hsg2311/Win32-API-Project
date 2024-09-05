#ifndef __ANIMATOR_HPP
#define __ANIMATOR_HPP

#include <map>
#include <string>

class Animation;

class Animator {
public:
	Animator( );
	~Animator( );

	void createAnimation( );
	void findAnimation( );
	void play( );

private:
	std::map<std::wstring, Animation*> animations_;
};

#endif // __ANIMATOR_HPP