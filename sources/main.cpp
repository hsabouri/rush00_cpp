#include "AbstractGameEntity.hpp"
#include "Moving.hpp"
#include <iostream>

int main(void) {
	Moving yolo(50.0f, 50.0f, 254, 10.0f, 0.0f, 10.0f, 1.0f);

	std::cout << yolo.getSpeedX() << " - " << yolo.getSpeedY() << std::endl;
	yolo.movement();
	std::cout << yolo.getSpeedX() << " - " << yolo.getSpeedY() << std::endl;
	yolo.movement();
}
