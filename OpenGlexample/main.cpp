#include <iostream>
#include <GL/glew.h>
#include "Display.h"


int main(int argc, char ** argv) {
	Display display(800, 600, "hello");
	while (!display.IsClosed()) {
		display.Clear(0.5f,0.3f,1.0f,0.6f);
		display.Update();
	}
	return 0;
}