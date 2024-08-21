#include "pch.h"
#include "InputDeviceHandler.hpp"

InputDeviceHandler::InputDeviceHandler( )
	: inputDataInfo_{ }
{
	inputDataInfo_.reserve( static_cast<UINT>( InputData::EOE ) );
}

InputDeviceHandler::~InputDeviceHandler( )
{}

void InputDeviceHandler::init( )
{
	for ( UINT i = 0; i < static_cast<UINT>( InputData::EOE ); ++i ) {
		inputDataInfo_.emplace_back( KEY_STATE::NONE, false );
	}
}

void InputDeviceHandler::update( )
{

}