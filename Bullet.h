/*
 * Bullet.h
 *
 *  Created on: 2014. 12. 16.
 *      Author: dohyun.jo
 */

#ifndef OBJECT_BULLET_H_
#define OBJECT_BULLET_H_
#include "cocos2d.h"
#include "../GameController.h"
//#include "../layer/GameLayer.h"
#include <string>
USING_NS_CC;

class Bullet : public Sprite
{
protected:
	string _image = "";
	int _x = 0, _y = 0, _v = 0;;
	bool _alive = false;


public:
	Bullet();
	virtual ~Bullet();
	Bullet(string image, int x, int y);
	void checkBounded(float dt);
	Rect collideRect(Point p);
};

#endif /* OBJECT_BULLET_H_ */
