#pragma once

#include "Engine.h"

enum JOYSTICK_BUTTON{
	JOYSTICK_BUTTON_A = 0,
	JOYSTICK_BUTTON_B = 1,
	JOYSTICK_BUTTON_X = 2,
	JOYSTICK_BUTTON_Y = 3,
	JOYSTICK_BUTTON_LEFT = 4,
	JOYSTICK_BUTTON_RIGHT = 5
};

class InputManager
{
public:
	InputManager();
	~InputManager();

	static bool m_joystickConnected;
	static int2 m_mouseCoor;
	static const Uint8* m_keyboardState;
	static float2 m_joyLeftStickCoor;
	static float2 m_joyRightStickCoor;
	static polar m_joyLeftStickPol;
	static polar m_joyRightStickPol;
	static float m_joyLeftTriggerVal;
	static float m_joyRightTriggerVal;

	void init();
	void handleInput();
	void setMouseMultiply(float2 multyplier);
	void destroy();

	static bool isMousePressed();
	static bool isJoyButtonPressed(JOYSTICK_BUTTON button);

private:
	SDL_Event m_event;

	float2 m_mouseMultiply;
	int m_joystickDeadzone = 5000; /// TODO: config

	SDL_Joystick* m_joystick;
	int2 m_leftJoystickRaw, m_rightJoystickRaw;
	float m_leftTriggerRaw, m_rightTriggerRaw;

	static bool m_mouseIsPressed;
	
	static bool m_joyButtonPressed[6];

	void normaliseStickValuesWithDeadzone(int2 stick, float2* normalised, polar* normalisedPolar);
	void normaliseTriggerValueWithDeadzone(float trigger, float* normalised);
};


bool isAnyKeyPressed();
bool isKeyPressed(SDL_Scancode code);