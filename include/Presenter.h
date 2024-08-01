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
	void draw() const;
	void destroy();

	static void drawObject(SDL_Texture* texture);
	static void drawObject(const Drawable& drawable);
	static void drawObject(const Drawable& drawable, float angle);

private:
	void improveRenderer();
};

template <typename... Params>
void drawObject(const Params... value)
{
	Presenter::drawObject(value...);
}

SDL_Texture* loadTexture(string path);