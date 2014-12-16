/*
 * NormalBullet.h
 *
 *  Created on: 2014. 12. 16.
 *      Author: dohyun.jo
 */

#ifndef OBJECT_NORMALBULLET_H_
#define OBJECT_NORMALBULLET_H_

#include "Bullet.h"

class NormalBullet: public Bullet
{
private:
	//int _a = 0;

public:
	NormalBullet();
	//NormalBullet(string image, int x, int y, int v, int a);
	virtual ~NormalBullet();
	//void update(float dt);
	//Rect collideRect(Point p);
	//void destroy();
};

#endif /* OBJECT_NORMALBULLET_H_ */
