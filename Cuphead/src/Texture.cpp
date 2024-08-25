#include "pch.h"
#include "Texture.hpp"

Texture::Texture( )
	: texDc_{ nullptr }
	, texImage_{ }
{
}

Texture::~Texture( )
{
	
}

void Texture::Load( const std::wstring& filePath )
{
	texImage_.Load( filePath.c_str( ) );
}
