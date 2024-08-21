#ifndef __INPUT_DEVICE_HANDLER_HPP
#define __INPUT_DEVICE_HANDLER_HPP

enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY
};

enum class InputData
{
	LEFT,
	RIGHT,
	UP,
	DOWN,

	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	Z,
	X,
	C,
	V,
	B,
	N,
	M,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	EOE
};

struct InputDataInfo
{
	KEY_STATE state;
	bool isPressed;
};

class InputDeviceHandler
{
	SINGLETON( InputDeviceHandler );

public:
	void init( );
	void update( );

private:
	std::vector<InputDataInfo> inputDataInfo_;
};

#endif // __INPUT_DEVICE_HANDLER_HPP