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
		float newX = InputManager::m_mouseCoor.x - d.drect.w/2;
		float newY = InputManager::m_mouseCoor.y - d.drect.h/2;
		float xDiff = newX - d.drect.x;
		float yDiff = newY - d.drect.y;
		if (xDiff*xDiff + yDiff*yDiff > 0) {
			m_angle = atan2(-yDiff, xDiff);
			d.drect.x = newX;
			d.drect.y = newY;
		}
	}else

	if (InputManager::m_joyLeftStickPol.rad != 0) {
		m_angle = InputManager::m_joyLeftStickPol.angle;

		float speed = InputManager::m_joyLeftStickPol.rad * (1 + InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_LEFT) * 2);

		acc.x += cos(m_angle) * speed;
		acc.y -= sin(m_angle) * speed;
	}
	d.angle = m_angle;
	m_aiming = (InputManager::m_joyRightStickPol.rad != 0);
	Uint64 currTime = SDL_GetPerformanceCounter();
	if (!InputManager::m_joystickConnected && InputManager::m_keyboardState[SDL_SCANCODE_SPACE] && (currTime - lastShotTime) > 800000.0f) { /// TODO: this is only for developement debugging
		shoot();
		(*Game::m_bullets.rbegin())->d.angle = m_angle;
		lastShotTime = currTime;
	}else

	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_RIGHT) && (currTime - lastShotTime) > 800000.0f) {
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
	Bullet* newBullet = new Bullet;
	newBullet->spawn({ d.drect.x,d.drect.y }, InputManager::m_joyRightStickPol.angle, true);
	Game::m_bullets.push_back(newBullet);
}
