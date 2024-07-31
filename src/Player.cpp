#include "Player.h"
#include "InputManager.h"

Player::Player(){}

Player::~Player(){}

void Player::init() {
	angle = toRad(30);
	d.drect.x = Presenter::m_SCREEN_WIDTH / 2;
	d.drect.y = Presenter::m_SCREEN_HEIGHT / 2;
	d.drect.w = 100;
	d.drect.h = 100;
	d.texture = loadTexture("Player2.bmp");

}

void Player::update() {
	if (!InputManager::m_joystickConnected) { /// TODO: this is only for developement debugging
		d.drect.x = InputManager::m_mouseCoor.x - d.drect.w/2;
		d.drect.y = InputManager::m_mouseCoor.y - d.drect.h/2;
		return;
	}

	angle = InputManager::m_joyRightStickPol.angle;

	speed = 9 * InputManager::m_joyRightStickPol.rad * (1 + InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_RIGHT) * 2);

	d.drect.x += cos(angle) * speed;
	d.drect.y -= sin(angle) * speed;
	//cout << d.drect.x << " " << d.drect.y << endl;

	if (d.drect.x < 0) { d.drect.x = 0; }
	if (d.drect.y < 0) { d.drect.y = 0; }
	if (d.drect.x >= Presenter::m_SCREEN_WIDTH - d.drect.w) { d.drect.x = Presenter::m_SCREEN_WIDTH - d.drect.w -1; }
	if (d.drect.y >= Presenter::m_SCREEN_HEIGHT - d.drect.h) { d.drect.y = Presenter::m_SCREEN_HEIGHT - d.drect.h -1; }
}
