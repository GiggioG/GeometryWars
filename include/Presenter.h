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
	void destroy();

	static void drawObject(SDL_Texture* texture);
	static void drawObject(Drawable& drawable);

private:
	void improveRenderer();
};

template <typename Params>
void drawObject(Params& value)
{
	Presenter::drawObject(value);
}

SDL_Texture* loadTexture(string path);