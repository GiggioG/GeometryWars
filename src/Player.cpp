#include "Player.h"

Player::Player(){}

Player::~Player(){}

void Player::init() {
	angle = toRad(30);
	d.drect.x = Presenter::m_SCREEN_WIDTH / 2;
	d.drect.y = Presenter::m_SCREEN_HEIGHT / 2;
	d.drect.w = 100;
	d.drect.h = 100;
	d.texture = loadTexture("Player1.bmp");

}

void Player::update() {
	d.drect.x += cos(angle) * speed;
	d.drect.y -= sin(angle) * speed;
	//cout << d.drect.x << " " << d.drect.y << endl;

	angle += 0.05;
}
