/*
 * Flight.h
 *
 *  Created on: 2014. 12. 12.
 *      Author: dohyun.jo
 */

#ifndef FIGHTER_FLIGHT_H_
#define FIGHTER_FLIGHT_H_
#include "cocos2d.h"
#include "../GameController.h"
#include "../layer/GameLayer.h"
USING_NS_CC;


class Flight : public Sprite{
private:
	//zOrder: FLANKER.CONFIG.ZORDER.PLAYER,
	bool op = false, isAnimate = true, _alive = true, isLethal = false, canBeAttack = false;

	int speed = 200, dt = 0, _power = 1, lethal = 0, dx = 0, dy = 0, direction = 0;

	int Life = 0;

	int key_UP = 11, key_DOWN= 11, key_LEFT= 11,	key_RIGHT= 11, key_SHOOT= 11, key_BOOM= 11;//수정필요

	int HP = 0, _hurtColorLife = 0;
	Point appearPosition = Point(160, 0);

	Sprite* bornSprite = NULL;
	Sprite* playerSprite = NULL;






public:
	Flight();
	virtual ~Flight();
	void reborn();
	void born();
	void demage();
	void initBornSprite();
	void shoot();
	void lethalShoot();
	void hurt();
	Rect collideRect(Point p);
	void levelUp();
	void move(float dt);
	void update(int dt);
	void destroy();
	void setDelta(int dx, int dy, int direction);

};

#endif /* FIGHTER_FLIGHT_H_ */
