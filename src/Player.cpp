#include "Player.h"

Player::Player(){}

Player::~Player(){}

void Player::init() {
	texture = loadTexture("Player1.bmp");
	angle = toRad(30);
	coord.x = Presenter::m_SCREEN_WIDTH / 2;
	coord.y = Presenter::m_SCREEN_HEIGHT / 2;
}

void Player::update() {
	//coord.x += cos(angle) * speed;
	//coord.y -= sin(angle) * speed;
	angle += 0.05;
}

void Player::draw() {
	Drawable d;
	d.rect.x = (int)coord.x;
	d.rect.y = (int)coord.y;
	d.rect.w = 100;
	d.rect.h = 100;
	d.texture = texture;
	SDL_Point pivot = { 100, 100 };
	drawObject(d, angle - (M_PI / 2), &pivot);
}

void Player::destruct() {
	SDL_DestroyTexture(texture);
}
