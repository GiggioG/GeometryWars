#include "InputManager.h"

bool InputManager::m_mouseIsPressed = bool();
bool InputManager::m_joyButtonPressed[6] = { bool() };

int2 InputManager::m_mouseCoor = int2();

const Uint8* InputManager::m_keyboardState = nullptr;

float2 InputManager::m_joyLeftStickCoor = float2();
float2 InputManager::m_joyRightStickCoor = float2();

polar InputManager::m_joyLeftStickPol = polar();
polar InputManager::m_joyRightStickPol = polar();

float InputManager::m_joyLeftTriggerVal = float();
float InputManager::m_joyRightTriggerVal = float();

InputManager::InputManager(){}
InputManager::~InputManager(){}

void InputManager::init() {
	if (SDL_NumJoysticks() < 1) {
		cerr << "ERROR: No Joystick connected\n";
		return;
	}
	m_joystick = SDL_JoystickOpen(0);
	if (m_joystick == nullptr) {
		cerr << "ERROR: Couldn't open game controller! SDL Error: " << SDL_GetError() << '\n';
		return;
	}
	for (int i = 0; i < 6; i++) {
		m_joyButtonPressed[i] = false;
	}
}

void InputManager::setMouseMultiply(float2 multyplier)
{
	m_mouseMultiply.x = multyplier.x;
	m_mouseMultiply.y = multyplier.y;
}

void InputManager::destroy(){
	SDL_JoystickClose(m_joystick);
	m_joystick = nullptr;
}

void InputManager::handleInput()
{
	m_mouseIsPressed = false;

	//Events for the mouse
	while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type)
		{
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&(m_mouseCoor.x), &(m_mouseCoor.y));

			m_mouseCoor.x *= m_mouseMultiply.x;
			m_mouseCoor.y *= m_mouseMultiply.y;

			break;
		case SDL_MOUSEBUTTONDOWN:
			if (m_event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseIsPressed = true;
			}
			break;
		case SDL_JOYAXISMOTION: {
			int axis = m_event.jaxis.axis;
			if (axis == 0) {
				m_leftJoystickRaw.x = m_event.jaxis.value;
			}
			else if (axis == 1) {
				m_leftJoystickRaw.y = m_event.jaxis.value;
			}
			else if (axis == 2) {
				m_rightJoystickRaw.x = m_event.jaxis.value;
			}
			else if (axis == 3) {
				m_rightJoystickRaw.y = m_event.jaxis.value;
			}
			else if (axis == 4) {
				m_joyLeftTriggerVal = (float)m_event.jaxis.value / 32767;
			}
			else if (axis == 5) {
				m_joyRightTriggerVal = (float)m_event.jaxis.value / 32767;
			}
			break;
		}
		case SDL_JOYBUTTONDOWN:
			if (m_event.jbutton.button >= 0 && m_event.jbutton.button <= 6) {
				m_joyButtonPressed[m_event.jbutton.button] = true;
			}
			break;
		case SDL_JOYBUTTONUP:
			if (m_event.jbutton.button >= 0 && m_event.jbutton.button <= 6) {
				m_joyButtonPressed[m_event.jbutton.button] = false;
			}
			break;
		}
	}
	normaliseStickValuesWithDeadzone(m_leftJoystickRaw, &m_joyLeftStickCoor, &m_joyLeftStickPol);
	normaliseStickValuesWithDeadzone(m_rightJoystickRaw, &m_joyRightStickCoor, &m_joyRightStickPol);

	m_keyboardState = SDL_GetKeyboardState(NULL);
}

bool InputManager::isMousePressed()
{
	return m_mouseIsPressed;
}

bool InputManager::isJoyButtonPressed(JOYSTICK_BUTTON button){
	return m_joyButtonPressed[button];
}

void InputManager::normaliseStickValuesWithDeadzone(int2 stick, float2* normalised, polar* normalisedPolar) {
	bool deadZone = (stick.x * stick.x + stick.y * stick.y < m_joystickDeadzone * m_joystickDeadzone);
	if (deadZone) {
		stick.x = 0;
		stick.y = 0;
	}
	normalised->x = (float)stick.x / 32767.0f;
	normalised->y = (float)stick.y / 32767.0f;

	normalisedPolar->rad = normalised->x * normalised->x + normalised->y * normalised->y;
	if (!deadZone) {
		normalisedPolar->angle = atan2(-normalised->y, normalised->x);
	}
}

bool isAnyKeyPressed()
{
	int numOfKeys = 322;

	for (int i = 0; i < numOfKeys; i++)
	{
		if (InputManager::m_keyboardState[i])
		{
			return true;
		}
	}

	return false;
}

bool isKeyPressed(SDL_Scancode code)
{
	return InputManager::m_keyboardState[code];
}
