#include "common.h"



Lists::Lists()
{
	enemyList[0] = Unit(0, 0, "img/sly_fox.png", "Sly fox", 4, 2, 0, 50, 0);
	enemyList[1] = Unit(0, 0, "img/blue_snowman.png", "Blue snowman", 5, 10, 10, 5, 1);
	/*enemyList[0].getTexture()->loadFromFile("img/sly_fox.png");
	enemyList[1].getTexture()->loadFromFile("img/blue_snowman.png");*/
	/*{
		Unit(0, 0, "img/enemy1.png", "Sly fox", 4, 2, 0, 50, 0),
		Unit(0, 0, "img/enemy2.png", "Blue snowman", 10, 10, 10, 5, 1)
	};*/

	itemList[0] = Item("Leather armor", 5, 0, 4, 20, BODY);
	itemList[1] = Item("Helmet", 5, 0, 5, 0, HEAD);
	itemList[2] = Item("Battle Axe", 0, 25, 1, -10, WEAPON);
	itemList[3] = Item("Monk wristbands", 0, 0, 1, 25, ARMS);
	itemList[4] = Item("Supreme Shield", 100, 2, 50, -100, WEAPON);
	/*itemList[2] = {
		Item("Leather armor", 5, 0, 4, 20, BODY),
		Item("Sword", 0, 15, 1, 0, WEAPON)
	};*/

}
