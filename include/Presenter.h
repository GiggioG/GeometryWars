#pragma once

#include "Engine.h"

class Presenter
{
public:
	static SDL_Window* m_mainWindow;
	static SDL_Renderer* m_mainRenderer;

	static int m_SCREEN_WIDTH;
	static int m_SCREEN_HEIGHT;

	void init();
	void update();
	void draw();

	static void drawObject(SDL_Texture* texture);
	static void drawObject(Drawable& drawable);
	static void drawObject(Drawable& drawable, float angle, SDL_Point* pivot = NULL);
	static void drawObject(DrawableSrcRect& drawableSrcRect);

private:
	void improveRenderer();
};

template <typename Params>
void drawObject(Params& value)
{
	Presenter::drawObject(value);
}

template <typename Param1, typename Param2>
void drawObject(Param1& p1, Param2 p2){
	Presenter::drawObject(p1, p2);
}

template <typename Param1, typename Param2, typename Param3>
void drawObject(Param1& p1, Param2 p2, Param3 p3) {
	Presenter::drawObject(p1, p2, p3);
}

SDL_Texture* loadTexture(string path);