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
	coord.x += cos(angle) * speed;
	coord.y -= sin(angle) * speed;
	//angle += 0.05;
}

void Player::draw() {
	Drawable d;
	d.drect.x = (int)coord.x;
	d.drect.y = (int)coord.y;
	d.drect.w = 100;
	d.drect.h = 100;
	d.texture = texture;
	d.pivot = { 100, 100 };
	d.angle = angle;
	drawObject(d);
}

void Player::destruct() {
	SDL_DestroyTexture(texture);
}
