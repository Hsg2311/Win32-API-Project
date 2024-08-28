#ifndef __TEXTURE_HPP
#define __TEXTURE_HPP

#include "Res.hpp"
#include "struct.hpp"
#include <atlimage.h>
#include <string>
#include <Windows.h>

class Texture : public Res {
private:
	Texture( ) : texImage_{ } {};
	virtual ~Texture( ) {}

public:
	void Load( const std::wstring& filePath ) { texImage_.Load( filePath.c_str( ) ); }
	void Draw( HDC hdc, const Vec2& objPos ) { 
		texImage_.Draw( hdc, 
			static_cast<int>( objPos.x - texImage_.GetWidth( ) / 2.f ), 
			static_cast<int>( objPos.y - texImage_.GetHeight( ) / 2.f ), 
			texImage_.GetWidth( ), texImage_.GetHeight( ) ); 
	}

private:
	CImage texImage_;

	friend class ResourceHandler;
};

#endif // __TEXTURE_HPP