#ifndef __OBJECT_HPP
#define __OBJECT_HPP

class Collider;

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

	void CreateCollider( );

public:
	virtual void update( ) = 0;
	virtual void componentUpdate( ) final;
	virtual void render( HDC hdc ) = 0;
	virtual void componentRender( HDC hdc ) final;

private:
	Vec2 objPos_;
	Vec2 objScale_;

	Collider* collider_;
};

#endif // __OBJECT_HPP