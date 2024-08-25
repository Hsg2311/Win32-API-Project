#include "pch.h"
#include "PathHandler.hpp"

//#include "Core.hpp"

PathHandler::PathHandler( )
	: contentPath_{ fs::current_path( ) / "../" }
{}

PathHandler::~PathHandler( )
{}

void PathHandler::init( )
{
	auto pathCheck = 
	std::find_if( fs::recursive_directory_iterator( contentPath_ ),
		fs::end( fs::recursive_directory_iterator( contentPath_ ) ),
		[this]( const fs::directory_entry& entry ) {
			if ( entry.is_directory( ) 
				&& entry.path( ).filename( ) == "content" ) {
				contentPath_ = entry.path( );
				return true;
			}
			return false;
		}
	);
	
	if ( pathCheck == fs::end( fs::recursive_directory_iterator( contentPath_ ) ) ) {
		MessageBox( nullptr, L"content folder not found", L"Error", MB_OK );
		PostQuitMessage( 0 );
	}

	//SetWindowText( Core::GetInst( ).getHwnd( ), fs::canonical( contentPath_ ).c_str() );
}
