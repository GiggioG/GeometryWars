#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <SDL.h>

#define D(x) cerr << #x << " = " << (x) << " | " << __LINE__ << endl;
#define Dex(x) cerr << #x << " = " << (x) << " | " << __LINE__ << " " << __FILE__ << endl;
#define __FILE_NAME__ (strrchr(__FILE__, '\\' ) ? strrchr(__FILE__, '\\') + 1 : __FILE__)

using namespace std;

static string IMG_FOLDER = "img\\";
static string CONFIG_FOLDER = "config\\";
static string SOUND_FOLDER = "sound\\";

const float pi = M_PI;

typedef Uint32 Time;

struct polar {
	float rad;
	float angle;
};

struct int2 {
	int x;
	int y;

	void reset() {
		x = 0;
		y = 0;
	}

	void set(int2 b) {
		x = b.x;
		y = b.y;
	}

	void operator+=(int2 a)
	{
		x += a.x;
		y += a.y;
	}

	void operator-=(int2 a)
	{
		x -= a.x;
		y -= a.y;
	}

	void operator*=(int2 a)
	{
		x *= a.x;
		y *= a.y;
	}

	void operator/=(int2 a)
	{
		x /= a.x;
		y /= a.y;
	}

	int2 operator+(int2 a) const {
		return { x + a.x, y + a.y };
	}

	int2 operator-(int2 a) const {
		return { x - a.x, y - a.y };
	}

	int2 operator*(int2 a) const {
		return { x * a.x, y * a.y };
	}

	int2 operator/(int2 a) const {
		return { x / a.x, y / a.y };
	}

	int2 operator*(int a) const {
		return { x * a, y * a };
	}

	int2 operator/(int a) const {
		return { x / a, y / a };
	}

	int2 operator-() const {
		return { -x, -y };
	}

	bool operator==(int2 a) const {
		return (x == a.x && y == a.y);
	}

	bool operator!=(int2 a) const {
		return (x != a.x || y != a.y);
	}
};

struct float2 {
	float x;
	float y;

	void reset() {
		x = 0;
		y = 0;
	}

	void set(float2 b) {
		x = b.x;
		y = b.y;
	}

	void operator+=(float2 a)
	{
		x += a.x;
		y += a.y;
	}

	void operator-=(float2 a)
	{
		x -= a.x;
		y -= a.y;
	}

	void operator*=(float2 a)
	{
		x *= a.x;
		y *= a.y;
	}

	void operator/=(float2 a)
	{
		x /= a.x;
		y /= a.y;
	}

	float2 operator+(float2 a) const {
		return { x + a.x, y + a.y };
	}

	float2 operator-(float2 a) const {
		return { x - a.x, y - a.y };
	}

	float2 operator*(float2 a) const {
		return { x * a.x, y * a.y };
	}

	float2 operator/(float2 a) const {
		return { x / a.x, y / a.y };
	}

	float2 operator*(float a) const {
		return { x * a, y * a };
	}

	float2 operator/(float a) const {
		return { x / a, y / a };
	}

	float2 operator-() const {
		return { -x, -y };
	}

	bool operator==(float2 a) const {
		return (x == a.x && y == a.y);
	}

	bool operator!=(float2 a) const {
		return (x != a.x || y != a.y);
	}
};

struct double2 {
	double x;
	double y;

	void reset() {
		x = 0;
		y = 0;
	}

	void set(double2 b) {
		x = b.x;
		y = b.y;
	}

	void operator+=(double2 a)
	{
		x += a.x;
		y += a.y;
	}

	void operator-=(double2 a)
	{
		x -= a.x;
		y -= a.y;
	}

	void operator*=(double2 a)
	{
		x *= a.x;
		y *= a.y;
	}

	void operator/=(double2 a)
	{
		x /= a.x;
		y /= a.y;
	}

	double2 operator+(double2 a) const {
		return { x + a.x, y + a.y };
	}

	double2 operator-(double2 a) const {
		return { x - a.x, y - a.y };
	}

	double2 operator*(double2 a) const {
		return { x * a.x, y * a.y };
	}

	double2 operator/(double2 a) const {
		return { x / a.x, y / a.y };
	}

	double2 operator*(double a) const {
		return { x * a, y * a };
	}

	double2 operator/(double a) const {
		return { x / a, y / a };
	}

	double2 operator-() const {
		return { -x, -y };
	}

	bool operator==(double2 a) const {
		return (x == a.x && y == a.y);
	}

	bool operator!=(double2 a) const {
		return (x != a.x || y != a.y);
	}
};

struct Rect {
	double x, y;
	double w, h;
	SDL_Rect toSdlRect() const {
		return { (int)x, (int)y, (int)w, (int)h };
	}
};

struct RotatedRect {
	Rect rect;
	double angle;
};

struct Drawable {
	SDL_Texture* texture = nullptr;
	SDL_FRect drect = { 0 }; /// The rect where we draw
	SDL_Rect srect = { 0,0,1920,1080 }; /// The part of the sprite we draw   /// TODO - m_SCREEN_
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_Point pivot = {0,0};
	float angle = 0;
};

struct DrawableSrcRect : Drawable
{
	SDL_Rect srcRect;
};

enum SOUND
{
	BACKGORUND_MUSIC
};