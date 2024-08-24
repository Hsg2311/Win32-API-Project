#ifndef __TEXTURE_HPP
#define __TEXTURE_HPP

#include "Res.hpp"

class Texture : public Res
{
public:
	Texture( );
	virtual ~Texture( );

private:
	HDC texDc_;
	HBITMAP texBmp_;
};

#endif // __TEXTURE_HPP