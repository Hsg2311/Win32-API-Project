#ifndef __RESOURCE_HPP
#define __RESOURCE_HPP

#include <string>

class Res {
public:
	Res( ) : resKey_{ }, relativePath_{ } {}
	virtual ~Res( ) = 0 {}

public:
	void setResKey( const std::wstring& resKey ) { resKey_ = resKey; }
	void setRelativePath( const std::wstring& relativePath ) { relativePath_ = relativePath; }

	const std::wstring& getResKey( ) const { return resKey_; }
	const std::wstring& getRelativePath( ) const { return relativePath_; }

private:
	std::wstring resKey_;			// ���ҽ� Ű
	std::wstring relativePath_;		// ���ҽ� ��� ���
};

#endif // __RESOURCE_HPP