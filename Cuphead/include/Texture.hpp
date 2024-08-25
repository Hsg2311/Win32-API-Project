#ifndef __TEXTURE_HPP
#define __TEXTURE_HPP

#include "Res.hpp"

class Texture : public Res
{
private:
	Texture( );
	virtual ~Texture( );

public:
	void Load( const std::wstring& filePath );

private:
	HDC texDc_;
	CImage texImage_;

	friend class ResourceHandler;
};

#endif // __TEXTURE_HPP