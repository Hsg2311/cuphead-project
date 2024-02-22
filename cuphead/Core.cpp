#include "pch.h"
#include "Core.h"

Core::Core( )
	: hWnd_{ nullptr }
	, resolution_{ 0, 0 }
	, hDC_{ nullptr }
	, hBit_{ nullptr }
	, memDC_{ nullptr }
{

}

Core::~Core( )
{
	ReleaseDC( hWnd_, hDC_ );

	DeleteObject( hBit_ );
	DeleteDC( memDC_ );
}

int Core::init( HWND hWnd, POINT resolution )
{
	hWnd_ = hWnd;
	resolution_ = resolution;

	RECT rt{ 0, 0, resolution_.x, resolution_.y };
	AdjustWindowRect( &rt, WS_OVERLAPPEDWINDOW, false );
	SetWindowPos( hWnd_, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0 );

	hDC_ = GetDC( hWnd_ );

	hBit_ = CreateCompatibleBitmap( hDC_, resolution_.x, resolution_.y );
	memDC_ = CreateCompatibleDC( hDC_ );

	HBITMAP defaultBitmap = (HBITMAP)SelectObject( memDC_, hBit_ );
	DeleteObject( defaultBitmap );

	return S_OK;
}

void Core::progress( )
{

}
