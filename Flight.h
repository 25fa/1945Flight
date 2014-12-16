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
#include "../object/NormalBullet.h"
USING_NS_CC;


class Flight : public Sprite{
private:
	//zOrder: FLANKER.CONFIG.ZORDER.PLAYER,
	bool op = false, isAnimate = true, _alive = true, isLethal = false, canBeAttack = false;

	int speed = 150, dt = 0, _power = 1, lethal = 0, dx = 0, dy = 0, direction = 0;
	double deltax = 0.0f, deltay = 0.0f;

	int Life = 0;

	bool key_UP, key_DOWN, key_LEFT, key_RIGHT, key_SHOOT, key_BOOM;

	int HP = 0, _hurtColorLife = 0;
	Point appearPosition = Point(160, 0);

	Sprite* bornSprite = NULL;
	Sprite* playerSprite = NULL;

	Size size;

	Label *lb;





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


	void update(float dt);
	void destroy();
	void setDelta(double dx, double dy);
	void setDeltaXY(double dx, double dy);

	bool isKeyBoom() const {
		return key_BOOM;
	}

	void setKeyBoom(bool keyBoom) {
		key_BOOM = keyBoom;
	}

	bool isKeyDown() const {
		return key_DOWN;
	}

	void setKeyDown(bool keyDown) {
		key_DOWN = keyDown;
	}

	bool isKeyLeft() const {
		return key_LEFT;
	}

	void setKeyLeft(bool keyLeft) {
		key_LEFT = keyLeft;
	}

	bool isKeyRight() const {
		return key_RIGHT;
	}

	void setKeyRight(bool keyRight) {
		key_RIGHT = keyRight;
	}

	bool isKeyShoot() const {
		return key_SHOOT;
	}

	void setKeyShoot(bool keyShoot) {
		key_SHOOT = keyShoot;
	}

	bool isKeyUp() const {
		return key_UP;
	}

	void setKeyUp(bool keyUp) {
		key_UP = keyUp;
	}

	int getDt() const {
		return dt;
	}

	void setDt(int dt = 0) {
		this->dt = dt;
	}
};

#endif /* FIGHTER_FLIGHT_H_ */
