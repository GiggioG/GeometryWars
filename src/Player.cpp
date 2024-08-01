#include "Player.h"
#include "InputManager.h"
#include "Game.h"

extern float deltaTime;

Player::Player(){}

Player::~Player(){}

void Player::init() {
	m_angle = 30*pi/180;
	d.drect.x = Presenter::m_SCREEN_WIDTH / 2;
	d.drect.y = Presenter::m_SCREEN_HEIGHT / 2;
	d.drect.w = 100;
	d.drect.h = 100;
	d.texture = loadTexture("Player2.bmp");

}

Uint64 lastShotTime = 0;

void Player::update() {
	if (!InputManager::m_joystickConnected) { /// TODO: this is only for developement debugging
		d.drect.x = InputManager::m_mouseCoor.x - d.drect.w/2;
		d.drect.y = InputManager::m_mouseCoor.y - d.drect.h/2;
		return;
	}

	if (InputManager::m_joyLeftStickPol.rad != 0) {
		m_angle = InputManager::m_joyLeftStickPol.angle;

		float speed = InputManager::m_joyLeftStickPol.rad * (1 + InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_LEFT) * 2);

		acc.x += cos(m_angle) * speed;
		acc.y -= sin(m_angle) * speed;
	}
	d.angle = m_angle;
	m_aiming = (InputManager::m_joyRightStickPol.rad != 0);
	Uint64 currTime = SDL_GetPerformanceCounter();
	//if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_RIGHT) && (currTime - lastShotTime) > 800000.0f * deltaTime) {
	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_RIGHT) && (currTime - lastShotTime) > 8000000.0f) {
		shoot();
		lastShotTime = currTime;
	}
	Entity::update();

	if (d.drect.x < 0) { d.drect.x = 0; }
	if (d.drect.y < 0) { d.drect.y = 0; }
	if (d.drect.x >= Presenter::m_SCREEN_WIDTH - d.drect.w) { d.drect.x = Presenter::m_SCREEN_WIDTH - d.drect.w -1; }
	if (d.drect.y >= Presenter::m_SCREEN_HEIGHT - d.drect.h) { d.drect.y = Presenter::m_SCREEN_HEIGHT - d.drect.h -1; }
}

void Player::shoot()
{
	Bullet temp_b;
	temp_b.spawn({ d.drect.x,d.drect.y }, InputManager::m_joyRightStickPol.angle, true);
	Game::m_bullets.push_back(temp_b);
}
