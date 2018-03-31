#include <Ennemy.hpp>
#include <Window.hpp>

int main(void) {
	
	Window win = Window();

	Ennemy en = Ennemy(10.0f, 10.0f, 0.0f, 5.0f);

	win.init();
	int i;

	while (1) {
		win.refresh();
	}
}
