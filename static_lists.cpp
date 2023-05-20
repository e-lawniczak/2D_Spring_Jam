#include "common.h"


Unit Lists::enemyList[2] = {
	Unit(0, 0, "img/enemy1.png", "Sly fox", 4, 2, 0, 50, 0),
	Unit(0, 0, "img/enemy2.png", "Blue snowman", 10, 10, 10, 5, 1)
};

Item Lists::itemList[2] = {
	Item("Leather armor", 5, 0, 4, 20, BODY),
	Item("Sword", 0, 15, 1, 0, WEAPON)
};
