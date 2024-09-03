#ifndef __OBJECT_HPP
#define __OBJECT_HPP

#include "Collider.hpp"
#include <string>

class Object {
public:
	Object( ) : objName_{ }, objPos_ { }, objScale_{ }, collider_{ nullptr }, alive_{ true } {}
	virtual ~Object( ) = 0 { delete collider_; }

public:
	void setObjName( const std::wstring& objName ) { objName_ = objName; }
	void setObjPos( const Vec2& objPos ) { objPos_ = objPos; }
	void setObjScale( const Vec2& objScale ) { objScale_ = objScale; }

	const std::wstring& getObjName( ) const { return objName_; }
	Vec2 getObjPos( ) const { return objPos_; }
	Vec2 getObjScale( ) const { return objScale_; }

	Collider* getCollider( ) const { return collider_; }

	bool IsAlive( ) const { return alive_; }

public:
	void CreateCollider( ) { collider_ = new Collider{ }; }

	virtual void OnCollision( Object* other ) {}
	virtual void OnCollisionEntry( Object* other ) {}
	virtual void OnCollisionExit( Object* other ) {}

public:
	virtual void update( ) = 0 {
	}

	virtual void componentUpdate( ) final {
		if ( collider_ ) {
			collider_->update( getObjPos( ) );
		}
	}

	virtual void render( HDC hdc ) = 0 {
		Rectangle( hdc
			, static_cast<int>( objPos_.x - objScale_.x / 2.f )
			, static_cast<int>( objPos_.y - objScale_.y / 2.f )
			, static_cast<int>( objPos_.x + objScale_.x / 2.f )
			, static_cast<int>( objPos_.y + objScale_.y / 2.f ) );

		componentRender( hdc );
	}

	virtual void componentRender( HDC hdc ) final {
		if ( collider_ ) {
			collider_->render( hdc );
		}
	}

private:
	std::wstring objName_;
	Vec2 objPos_;
	Vec2 objScale_;

	Collider* collider_;

	bool alive_;
	friend class EventHandler;
};

#endif // __OBJECT_HPP