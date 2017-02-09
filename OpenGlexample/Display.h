#pragma once 
#include <SDL2/SDL.h>
#include <string>
#include <GL/glew.h>

class Display //����ʹ��SDL�� ������һ��OpenGl���ƵĴ���
{
public:
	Display(int width, int height, const std::string &title);
	~Display();
	bool IsClosed();//getter of m-isClosed
	void Clear(float r, float g, float b, float a);//ʹ��rgba ��ɫֵ����ջ���
	void Update();//���»���
protected:
private:
	SDL_Window * m_window;//window
	SDL_GLContext m_glCtx;// glcontext
	bool m_isClosed;// ���ڹرճ�����ж�
};

