#include "Player.h"
#include "InputManager.h"

Player::Player(){}

Player::~Player(){}

void Player::init() {
	texture = loadTexture("Player1.bmp");
	angle = toRad(30);
	coord.x = Presenter::m_SCREEN_WIDTH / 2;
	coord.y = Presenter::m_SCREEN_HEIGHT / 2;
}

void Player::update() {
	coord.x = InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_LEFT) * Presenter::m_SCREEN_WIDTH;
	coord.y = InputManager::isJoyButtonPressed(JOYSTICK_BUTTON_RIGHT) * Presenter::m_SCREEN_HEIGHT;
}

void Player::draw() {
	Drawable d;
	d.drect.w = 100;
	d.drect.h = 100;
	d.drect.x = (int)coord.x - d.drect.w/2;
	d.drect.y = (int)coord.y - d.drect.h/2;
	d.texture = texture;
	d.pivot = { 100, 100 };
	drawObject(d);
}

void Player::destruct() {
	SDL_DestroyTexture(texture);
}
