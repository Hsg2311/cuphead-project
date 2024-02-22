#ifndef __Core
#define __Core

class Core
{
	SINGLETON( Core );

public:
	int init( HWND hWnd, POINT resolution );
	void progress( );

	HWND GetMainHWND( ) { return hWnd_; }

private:
	HWND hWnd_;
	POINT resolution_;
	HDC hDC_;

	HBITMAP hBit_;
	HDC memDC_;
};

#endif	// __Core