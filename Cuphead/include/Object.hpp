#ifndef __OBJECT_HPP
#define __OBJECT_HPP

class Object
{
public:
	Object( );
	virtual ~Object( ) = 0;

public:
	void setObjPos( const Vec2& objPos ) { objPos_ = objPos; }
	void setObjScale( const Vec2& objScale ) { objScale_ = objScale; }

	Vec2 getObjPos( ) const { return objPos_; }
	Vec2 getObjScale( ) const { return objScale_; }

private:
	Vec2 objPos_;
	Vec2 objScale_;
};

#endif // __OBJECT_HPP