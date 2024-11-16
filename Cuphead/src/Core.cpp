#include "Core.hpp"
#include "PathHandler.hpp"
#include "Timer.hpp"
#include "InputDeviceHandler.hpp"
#include "SceneHandler.hpp"
#include "CollisionHandler.hpp"
#include "EventHandler.hpp"
#include "Camera.hpp"

#include <ranges>
#include <algorithm>

Core::Core( )
	: hWnd_{ nullptr }
	, resolution_{ }
	, hdc_{ nullptr }
	, hBitmap_{ nullptr }
	, hMemDC_{ nullptr }
	, hPen_{ }
	, hBrush_{ }
{}

Core::~Core( ) {
	ReleaseDC( hWnd_, hdc_ );
	DeleteDC( hMemDC_ );
	DeleteObject( hBitmap_ );

	std::ranges::for_each( hPen_, []( HPEN& pen ) { DeleteObject( pen ); } );
	std::ranges::for_each( hBrush_, []( HBRUSH& brush ) { DeleteObject( brush ); } );
}

int Core::init( HWND hWnd, POINT resolution ) {
	hWnd_ = hWnd;
	resolution_ = resolution;

	// �ػ� ����
	RECT rc{ 0, 0, resolution_.x, resolution_.y };
	AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, false );
	SetWindowPos( hWnd_, nullptr, 10, 10, rc.right - rc.left, rc.bottom - rc.top, 0 );

	// ���� ������ DC ����
	hdc_ = GetDC( hWnd_ );

	// Double buffering �뵵�� ��Ʈ�ʰ� DC ����
	hBitmap_ = CreateCompatibleBitmap( hdc_, resolution_.x, resolution_.y );
	hMemDC_ = CreateCompatibleDC( hdc_ );
	HBITMAP defaultBmp = (HBITMAP)SelectObject( hMemDC_, hBitmap_ );
	DeleteObject( defaultBmp );

	createPenBrush( );

	// Handler �ʱ�ȭ
	PathHandler::getInst( ).init( );
	Timer::getInst( ).init( );
	InputDeviceHandler::getInst( ).init( );
	SceneHandler::getInst( ).init( );
	Camera::getInst( ).init( );

	return S_OK;
}

void Core::progress( ) {
	// Handler update
	Timer::getInst( ).update( );
	InputDeviceHandler::getInst( ).update( );

	SceneHandler::getInst( ).update( );
	CollisionHandler::getInst( ).update( );
	Camera::getInst( ).update( );

	// Rendering (Double buffering)
	Rectangle( hMemDC_, -1, -1, resolution_.x + 1, resolution_.y + 1 );
	SceneHandler::getInst( ).render( hMemDC_ );
	BitBlt( hdc_, 0, 0, resolution_.x, resolution_.y, hMemDC_, 0, 0, SRCCOPY );

	Timer::getInst( ).render( );

	// Event ���� ó��
	EventHandler::getInst( ).update( );
}

void Core::createPenBrush( ) {
	hPen_[ static_cast<UINT>( PEN_TYPE::RED ) ] = CreatePen( PS_SOLID, 1, RGB( 255, 0, 0 ) );
	hPen_[ static_cast<UINT>( PEN_TYPE::GREEN ) ] = CreatePen( PS_SOLID, 1, RGB( 0, 255, 0 ) );
	hPen_[ static_cast<UINT>( PEN_TYPE::BLUE ) ] = CreatePen( PS_SOLID, 1, RGB( 0, 0, 255 ) );

	hBrush_[ static_cast<UINT>( BRUSH_TYPE::HOLLOW ) ] = (HBRUSH)GetStockObject( HOLLOW_BRUSH );
}
