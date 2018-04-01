#include <Player.hpp>
#include <Ennemy.hpp>
#include <Window.hpp>
#include <iostream>

int main(void) {
	
	Window win = Window();
	Window &win_ref = win;

	Ennemy en = Ennemy(10.0f, 140.0f, 0.0f, -0.0005f);
	Player pl = Player(10.0f, 10.0f);

	win.init();

	while (1) {
		en.movement();
		pl.moveBullet();
		pl.input(win_ref);
		win.updateDisplay(pl.getOldX(), pl.getOldY(), " ");
		win.updateDisplay(en.getOldX(), en.getOldY(), " ");
		win.updateDisplay(pl.getIntPosX(), pl.getIntPosY(), pl.getSkin());
		win.updateDisplay(en.getIntPosX(), en.getIntPosY(), en.getSkin());
		if (pl.bullet_ok) {
			win.updateDisplay(pl.bullet->getOldX(), pl.bullet->getOldY(), " ");
			win.updateDisplay(pl.bullet->getIntPosX(), pl.bullet->getIntPosY(), pl.bullet->getSkin());
		}
		win.refresh();
	}
}
