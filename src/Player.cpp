#include "Player.h"
#include "InputManager.h"
#include "Game.h"

extern float deltaTime;

Player::Player(){}

Player::~Player(){}

void Player::init() {
	angle = 30*pi/180;
	pos.x = Presenter::m_SCREEN_WIDTH / 2;
	pos.y = Presenter::m_SCREEN_HEIGHT / 2;
	d.drect.w = 100; /// TODO: config
	d.drect.h = 100;
	d.texture = loadTexture("Player2.bmp");
	health = 1000000;

	aimer = d;
	aimer.texture = loadTexture("Aiming.bmp");
}

Time lastShotTime;

void Player::update() {
	if (!InputManager::m_joystickConnected) { /// TODO: this is only for developement debugging
		float2 newPos = {InputManager::m_mouseCoor.x, InputManager::m_mouseCoor.y };
		float2 diff = newPos - pos;
		if (diff.x != 0 && diff.y != 0) {
			angle = atan2(-diff.y, diff.x);
			pos = newPos;
		}
	}
	else


	m_aiming = false;
	if (InputManager::m_joyRightStickPol.rad != 0) {
		aimer.angle = InputManager::m_joyRightStickPol.angle;
		m_aiming = true;
	}
	if (InputManager::m_joyLeftStickPol.rad != 0) {
		angle = InputManager::m_joyLeftStickPol.angle;

		/// TODO: refactor
		float speed = InputManager::m_joyLeftStickPol.rad * (1 + InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_LEFT) * 2);

		acc.x += cos(angle) * speed;
		acc.y -= sin(angle) * speed;
	}
	Time currTime = SDL_GetTicks();

	if (!InputManager::m_joystickConnected && InputManager::m_keyboardState[SDL_SCANCODE_SPACE] && (currTime - lastShotTime) > 200) { /// TODO: this is only for developement debugging
		shoot();
		(*Game::m_bullets.rbegin())->angle = angle;

	}else

	if (InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_RIGHT) && (currTime - lastShotTime) > 50) {
		shoot();
		lastShotTime = currTime;
	}
	if (currTime-lastShotTime < 50) {
		m_aiming = true;
	}
	Entity::update();

	if (pos.x < 0) { pos.x = 0; }
	if (pos.y < 0) { pos.y = 0; }
	if (pos.x >= Presenter::m_SCREEN_WIDTH) { pos.x = Presenter::m_SCREEN_WIDTH - 1; }
	if (pos.y >= Presenter::m_SCREEN_HEIGHT) { pos.y = Presenter::m_SCREEN_HEIGHT - 1; }
}

void Player::shoot() {
	Bullet* newBullet = new Bullet;
	newBullet->spawn(pos, InputManager::m_joyRightStickPol.angle, true, 10);
	Game::m_bullets.push_back(newBullet);
}

void Player::draw() {
	if (m_aiming) {
		aimer.drect.x = pos.x - d.drect.w / 2;
		aimer.drect.y = pos.y - d.drect.h / 2;
		drawObject(aimer);
	}
	Entity::draw();
}

void Player::checkBounds() {}