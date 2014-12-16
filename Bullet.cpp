/*
 * Bullet.cpp
 *
 *  Created on: 2014. 12. 16.
 *      Author: dohyun.jo
 */

#include "Bullet.h"


Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

Bullet::Bullet(string image, int x, int y)
{
	this->_x = x;
	this->_y = y;
	this->_image = image;
	if (GameController::getInstance()->g_sharedGameLayer->getState() == STATE_PLAYING) {
		GameController::getInstance()->g_sharedGameLayer->addBullet(this);
	}
}

void Bullet::checkBounded(float dt) {
	if(GameController::getInstance()->g_sharedGameLayer->getState() == STATE_PLAYING) {
		Size screenRect = GameController::getInstance()->g_sharedGameLayer->getScreenRect().size;//screenRect.size;
		float bulletRect = this->getContentSize().width;

		if(this->_x < -bulletRect || this->_x > screenRect.width + bulletRect || this->_y < -bulletRect || this->_y > screenRect.height + bulletRect - 15) {
			this->_alive = false;
		}
	}
}

Rect Bullet::collideRect(Point p) {
	Size a = this->getContentSize();
	return Rect(p.x - a.width / 2, p.y - a.height / 4, a.width, a.height / 2+20);
}
