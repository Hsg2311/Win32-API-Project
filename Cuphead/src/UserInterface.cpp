#include "UserInterface.hpp"
#include "ResourceHandler.hpp"

UserInterface::UserInterface( const std::wstring& resKey, const std::wstring& fileName, bool alpha )
	: texture_{ ResourceHandler::getInst( ).loadTexture( resKey, std::wstring( L"/texture/background/" + fileName ) ) }
{
	bAlpha_ = alpha;
	alpha_ = 254;
}

void UserInterface::render( HDC hdc ) {
	if ( bAlpha_ ) {
		
		texture_->draw( hdc, static_cast<int>( getObjPos( ).x ), static_cast<int>( getObjPos( ).y ),
			static_cast<int>( getObjScale( ).x ), static_cast<int>( getObjScale( ).y ),
			0, 0, texture_->getWidth( ), texture_->getHeight( ), alpha_ );
	}
	else {
		texture_->draw( hdc, static_cast<int>( getObjPos( ).x ), static_cast<int>( getObjPos( ).y ),
			static_cast<int>( getObjScale( ).x ), static_cast<int>( getObjScale( ).y ),
			0, 0, texture_->getWidth( ), texture_->getHeight( ) );
	}
}
