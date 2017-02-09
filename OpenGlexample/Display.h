#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <GL/glew.h>

class Display
{
public:
	Display(int width, int height, const std::string &title);
	~Display();
	bool IsClosed();
	void Clear(float r, float g, float b, float a);
	void Update();
protected:
private:
	SDL_Window * m_window;
	SDL_GLContext m_glCtx;
	bool m_isClosed;
};

