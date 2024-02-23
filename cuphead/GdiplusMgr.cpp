#include "pch.h"
#include "GdiplusMgr.h"

GdiplusMgr::GdiplusMgr( )
	: gpToken_{ }
	, gpsi_{ }
	, valid_{ true }
{
	if ( Gdiplus::GdiplusStartup( &gpToken_, &gpsi_, nullptr ) != Gdiplus::Status::Ok )
	{
		throw InitFailed{ };
	}
}

GdiplusMgr::~GdiplusMgr( )
{
	if ( valid_ )
	{
		Gdiplus::GdiplusShutdown( gpToken_ );
	}
}