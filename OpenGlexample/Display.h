#pragma once 
#include <SDL2/SDL.h>
#include <string>
#include <GL/glew.h>

class Display //此类使用SDL库 创建了一个OpenGl绘制的窗口
{
public:
	Display(int width, int height, const std::string &title);
	~Display();
	bool IsClosed();//getter of m-isClosed
	void Clear(float r, float g, float b, float a);//使用rgba 颜色值来清空画布
	void Update();//跟新画布
protected:
private:
	SDL_Window * m_window;//window
	SDL_GLContext m_glCtx;// glcontext
	bool m_isClosed;// 用于关闭程序的判定
};

