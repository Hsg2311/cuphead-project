#ifndef __GdiplusMgr
#define __GdiplusMgr

class GdiplusMgr
{
	LAZY_SINGLETON( GdiplusMgr );

public:
	GdiplusMgr( const GdiplusMgr& other ) = delete;
	GdiplusMgr& operator=( const GdiplusMgr& other ) = delete;

	GdiplusMgr( GdiplusMgr&& other ) noexcept
		: gpToken_{ other.gpToken_ }
		, gpsi_{ other.gpsi_ }
		, valid_{ std::exchange( other.valid_, false ) } { }

	GdiplusMgr& operator=( GdiplusMgr&& other ) noexcept
	{
		if ( this != &other )
		{
			gpToken_ = other.gpToken_;
			gpsi_ = other.gpsi_;
			valid_ = std::exchange( other.valid_, false );
		}

		return *this;
	}

public:
	class InitFailed : public std::exception
	{
	public:
		const char* what( ) const override
		{
			return "GDI+ 라이브러리를 초기화할 수 없습니다.";
		}
	};

private:
	ULONG_PTR gpToken_;
	Gdiplus::GdiplusStartupInput gpsi_;
	bool valid_;
};

#endif	// __GdiplusMgr