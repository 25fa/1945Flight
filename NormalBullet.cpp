/*
 * NormalBullet.cpp
 *
 *  Created on: 2014. 12. 16.
 *      Author: dohyun.jo
 */

#include "NormalBullet.h"



/*
NormalBullet::NormalBullet(string image, int x, int y, int v, int a){
	this->initWithSpriteFrameName(image);
	this->_x = x;
	this->_y = y;
	this->_v = v;
	this->_a = a;
	if(GameController::getInstance()->g_sharedGameLayer->getState() == STATE_PLAYING)
		GameController::getInstance()->g_sharedGameLayer->addBullet(this);

	this->_alive = true;
	this->schedule(schedule_selector(Bullet::checkBounded), 0);
	this->setPosition(this->_x, this->_y);
	this->scheduleUpdate();
}*/

NormalBullet::~NormalBullet() {
	// TODO Auto-generated destructor stub
}
/*
void NormalBullet::update(float dt)
{
	if(GameController::getInstance()->g_sharedGameLayer->getState() == STATE_PLAYING) {
		Point Sp = GameController::getInstance()->g_sharedGameLayer->getFlight()->getPosition();

		if(this->_a == FLANKER.ENEMY_ATTACK_MODE.GUIDED){

			if(Sp.x > this->_x ){
				this->_x += this->_x * 0.005;
			}
			if (Sp.x < this->_x ){
				this->_x -= this->_x * 0.005;
			}
		}

		this->_y += this->_v * dt;
		this->setPosition(this->_x, this->_y);
	}
}

Rect NormalBullet::collideRect(Point p) {
	Size a = this->getContentSize();
	return Rect(p.x - (a.width / 2) +3, p.y - (a.height / 2) + 3, a.width - 3, a.height -3);
}

void NormalBullet::destroy() {
	this->_alive = false;
	this->setVisible(false);
    this->stopAllActions();
}*/
