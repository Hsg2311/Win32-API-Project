#include "ResourceHandler.hpp"
#include "Res.hpp"
#include "Texture.hpp"
#include "PathHandler.hpp"
#include <cassert>
#include <ranges>

ResourceHandler::ResourceHandler( )
	: texMap_{ }
{}

ResourceHandler::~ResourceHandler( ) {
	std::ranges::for_each( texMap_, []( auto& tex ) {
		delete tex.second;
	} );
}

Texture* ResourceHandler::LoadTexture( const std::wstring& resKey, const std::wstring& relativePath ) {
	Texture* tex = FindTexture( resKey );
	if ( tex )
		return tex;

	auto filePath = PathHandler::GetInst( ).getContentPath( ).c_str( ) + relativePath;

	tex = new Texture{ };
	tex->Load( filePath );
	tex->setResKey( resKey );
	tex->setRelativePath( relativePath );

	texMap_.insert( std::make_pair( resKey, tex ) );
	
	return tex;
}

Texture* ResourceHandler::FindTexture( const std::wstring& resKey ) {
	auto tex = texMap_.find( resKey );

	if ( tex == texMap_.end( ) )
		return nullptr;

	assert( tex->second != nullptr );
	assert( dynamic_cast<Texture*>( tex->second ) != nullptr );

	return static_cast<Texture*>( tex->second );
}
