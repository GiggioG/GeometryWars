#pragma once

#include <iostream>
#include <fstream>
#include <SDL.h>

using namespace std;

static string IMG_FOLDER = "img\\";
static string CONFIG_FOLDER = "config\\";
static string SOUND_FOLDER = "sound\\";

const float pi = M_PI;

struct int2
{
	int x;
	int y;

	void reset()
	{
		x = 0;
		y = 0;
	}

	void set(int2 b)
	{
		x = b.x;
		y = b.y;
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

	int2 operator*(int2 a)
	{
		x *= a.x;
		y *= a.y;

		return *this; //Returns instance of the current class (After the modifications)
	}

	int2 operator/(int2 a)
	{
		x /= a.x;
		y /= a.y;

		return *this;
	}

	bool operator!=(int2 a)
	{
		if (x == a.x && y == a.y)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator==(int2 a)
	{
		if (x == a.x && y == a.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

struct polar {
	float rad;
	float angle;
};

struct float2
{
	//!!!IMPORTANT!!!
	float x;
	float y;

	void reset()
	{
		x = 0;
		y = 0;
	}

	void set(float2 b)
	{
		x = b.x;
		y = b.y;
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

	float2 operator*(float2 a)
	{
		x *= a.x;
		y *= a.y;

		return *this; //Returns instance of the current class (After the modifications)
	}

	float2 operator/(float2 a)
	{
		x /= a.x;
		y /= a.y;

		return *this;
	}

	bool operator!=(float2 a)
	{
		if (x == a.x && y == a.y)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator==(float2 a)
	{
		if (x == a.x && y == a.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

struct Drawable
{
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