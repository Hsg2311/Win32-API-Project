#include "pch.h"
#include "Core.hpp"

#include "Timer.hpp"

Core::Core( )
	: hWnd_{ nullptr }
	, resolution_{ }
	, hdc_{ nullptr }
	, hBitmap_{ nullptr }
	, hMemDC_{ nullptr }
{}

Core::~Core( ) 
{
	ReleaseDC( hWnd_, hdc_ );
	DeleteDC( hMemDC_ );
	DeleteObject( hBitmap_ );
}

int Core::init( HWND hWnd, POINT resolution ) 
{
	hWnd_ = hWnd;
	resolution_ = resolution;

	// 해상도 조정
	RECT rc{ 0, 0, resolution_.x, resolution_.y };
	AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, false );
	SetWindowPos( hWnd_, nullptr, 10, 10, rc.right - rc.left, rc.bottom - rc.top, 0 );

	// 메인 윈도우 DC 생성
	hdc_ = GetDC( hWnd_ );

	// Double buffering 용도의 비트맵과 DC 생성
	hBitmap_ = CreateCompatibleBitmap( hdc_, resolution_.x, resolution_.y );
	hMemDC_ = CreateCompatibleDC( hdc_ );
	HBITMAP defaultBmp = (HBITMAP)SelectObject( hMemDC_, hBitmap_ );
	DeleteObject( defaultBmp );

	// Manager 초기화
	Timer::GetInst( ).init( );

	return S_OK;
}

void Core::progress( )
{
	Timer::GetInst( ).update( );

	update( );

	Rectangle( hMemDC_, -1, -1, resolution_.x + 1, resolution_.y + 1 );
	render( );
	BitBlt( hdc_, 0, 0, resolution_.x, resolution_.y
		, hMemDC_, 0, 0, SRCCOPY );


	Timer::GetInst( ).render( );
}

void Core::update( )
{
}

void Core::render( )
{
}