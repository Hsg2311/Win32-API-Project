#ifndef __CORE_HPP
#define __CORE_HPP

class Core
{
	SINGLETON( Core );

public:
	int init( HWND hWnd, POINT resolution );
	void progress( );

	HWND getHwnd( ) const { return hWnd_; }

private:
	void update( );
	void render( );

private:
	HWND hWnd_;
	POINT resolution_;
	HDC hdc_;
};

#endif // __CORE_HPP