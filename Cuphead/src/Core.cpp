#include "pch.h"
#include "Core.hpp"

#include "Timer.hpp"

Core::Core( )
	: hWnd_{ nullptr }
	, resolution_{ }
	, hdc_{ nullptr }
{}

Core::~Core( ) 
{
	ReleaseDC( hWnd_, hdc_ );
}

int Core::init( HWND hWnd, POINT resolution ) 
{
	hWnd_ = hWnd;
	resolution_ = resolution;

	RECT rc{ 0, 0, resolution_.x, resolution_.y };
	AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, false );
	SetWindowPos( hWnd_, nullptr, 10, 10, rc.right - rc.left, rc.bottom - rc.top, 0 );

	hdc_ = GetDC( hWnd_ );

	Timer::GetInst( ).init( );

	return S_OK;
}

void Core::progress( )
{
	Timer::GetInst( ).update( );

	update( );

	render( );

	Timer::GetInst( ).render( );
}

void Core::update( )
{
}

void Core::render( )
{
}