#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "Object.hpp"
#include "Texture.hpp"

#include <string>
#include <vector>

class UserInterface : public Object {
public:
	UserInterface( const std::wstring& resKey, const std::wstring& fileName, bool alpha = true );
	UserInterface( Texture* tex, bool alpha )
		: texture_( tex )
		, textures_( )
		, bAlpha_( alpha )
		, alpha_( 254 ) {}

	virtual ~UserInterface( ) {}

	virtual void update( ) override {}
	virtual void render( HDC hdc ) override;

	virtual UserInterface* clone( ) override {
		return new UserInterface{ *this };
	}

private:
	Texture* texture_;
	std::vector<Texture*> textures_;
	bool bAlpha_;
	BYTE alpha_;
};

#endif 
// USERINTERFACE_HPP