#include "Camera.hpp"
#include "Object.hpp"

#include "InputDeviceHandler.hpp"
#include "Timer.hpp"

Camera::Camera( )
	: lookAt_( ), target_( nullptr ), diff_( ) {}

Camera::~Camera( ) {}

void Camera::update( ) {
	if ( target_ ) {
		if ( target_->isAlive( ) ) {
			lookAt_ = target_->getObjPos( );
		}
		else {
			target_ = nullptr;
		}
	}

	/*if ( KEY_HOLD( InputData::A ) ) {
		lookAt_.x -= 200.f * fDT;
	}
	if ( KEY_HOLD( InputData::D ) ) {
		lookAt_.x += 200.f * fDT;
	}
	if ( KEY_HOLD( InputData::W ) ) {
		lookAt_.y -= 200.f * fDT;
	}
	if ( KEY_HOLD( InputData::S ) ) {
		lookAt_.y += 200.f * fDT;
	}*/

	// ȭ�� �߾� ��ǥ�� ī�޶� lookAt_ ��ǥ�� ���̸� ���
	calDiff( );
}

void Camera::calDiff( ) {
	auto center = Vec2( Core::getInst( ).getResolution( ) ) / 2.f;
	diff_ = lookAt_ - center;
}
