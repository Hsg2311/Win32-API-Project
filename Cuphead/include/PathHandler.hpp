#ifndef __PATH_HANDLER_HPP
#define __PATH_HANDLER_HPP

class PathHandler
{
	SINGLETON( PathHandler );

public:
	void init( );
	const std::wstring& getContentPath( ) const { return contentPath_.wstring( ); }

private:
	fs::path contentPath_;
};

#endif // __PATH_HANDLER_HPP