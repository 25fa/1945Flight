/*
 * Flight.cpp
 *
 *  Created on: 2014. 12. 12.
 *      Author: dohyun.jo
 */

#include "Flight.h"

Flight::Flight() {
	// TODO Auto-generated constructor stub
/*	op = false, isAnimate = true, _alive = true, isLethal = false;

	speed = 200, dt = 0, _player = 0, _power = 1, lethal = 0, dx = 0, dy = 0, direction = 0;

	key_UP = 11, key_DOWN= 11, key_LEFT= 11,	key_RIGHT= 11, key_SHOOT= 11, key_BOOM= 11;//수정필요

	Point appearPostion = Point(160, 0);

	Sprite* bornSprite = NULL, playerSprite = NULL;*/

	//	this._power = FLANKER.PLAYER[player].POWER;
	this->Life = 3;
	this->setAnchorPoint(Point(0.5, 0.5));
	//init life
	this->initWithSpriteFrameName("ship_1_01.png");
	this->setScale(1.6);

	this->setPosition(160, 0);
	this->appearPosition = Point(160, 0);
	size = Director::getInstance()->getWinSize();
	GameController::getInstance()->g_sharedGameLayer->setState(STATE_PLAYING);

	this->born();

	this->scheduleUpdate();
	this->schedule(schedule_selector(Flight::move), 0);
	//this->initBornSprite();
	lb = Label::create("None", "arial", 50);
	lb->setAnchorPoint(ccp(0.5, 0.5));
	lb->setPosition(Point(100, 100));
	this->addChild(lb, 10);

}

Flight::~Flight() {
	// TODO Auto-generated destructor stub


}

void Flight::reborn()
{
	this->runAction( Sequence::create(DelayTime::create(1.0f), CallFunc::create( [&]() {
		this->setVisible(true);
		this->born();
	}), NULL));
}


void Flight::destroy(){
	GameLayer* _gameLayer = NULL;
	_gameLayer = GameController::getInstance()->g_sharedGameLayer;
	this->_alive = false;
	this->setVisible(false);

	//수정필요var explosion = Explosion.create(1);
	//수정필요explosion.setPosition(this.getPosition());
	if (_gameLayer->getState() == STATE_PLAYING)
	{
	/*	if(this.Life == 2){
	    	_gameLayer->_life1_2.setVisible(false);
		}else if(this.Life == 1){
			_gameLayer->_life1_1.setVisible(false);
		}*/

		this->Life--;

		if(this->Life > 0)
			this->reborn();
		else if(this->Life == 0)
		{
		/*	g_sharedGameLayer._lbPlayer1.setVisible(false);
					g_sharedGameLayer._lbScore1.setVisible(false);
					g_sharedGameLayer._lbSpecialLv1.setVisible(false);
					g_sharedGameLayer._gage1.setVisible(false);
					g_sharedGameLayer._boomb1.setVisible(false);
					g_sharedGameLayer._lbBoomb1.setVisible(false);

					var gameover2 = cc.Sprite.createWithSpriteFrameName("gameover.png");
					gameover2.setAnchorPoint(cc.p(0, 0.5));
					gameover2.setPosition(25, 450);

					var blink = cc.Blink.create(1, 1);
					var action = cc.RepeatForever.create(blink);
					gameover2.runAction(action);
					g_sharedGameLayer.addChild(gameover2, FLANKER.CONFIG.ZORDER.UI);*/
		}
	}
}


void Flight::update(float dt) {
	//lb->setString("update");
	if(this->_alive && GameController::getInstance()->g_sharedGameLayer->getState() == STATE_PLAYING)
	{
		Point pos = this->getPosition();

		if (this->op) {
			this->initWithSpriteFrameName("ship_1_01.png");
			this->setAnchorPoint(Point(0.5,0.5));
		}
		if(this->Life == 0){
			this->setVisible(false);
		}



		if(this->isAnimate)
		{
			if (this->key_UP && pos.y <= size.height) {
				this->op = true;
				this->initWithSpriteFrameName("ship_1_07.png");
				this->setAnchorPoint(Point(0.5,0.7));
				if(pos.y < 480 - this->getContentSize().height / 2)
					pos.y += deltay;
				double temp = deltay;
				string str = std::to_string(temp);
				lb->setString(str);
			}
			if (this->key_DOWN && pos.y >= 0) {
				this->op = true;
				this->initWithSpriteFrameName("ship_1_15.png");
				if(pos.y > this->getContentSize().height / 2 +7)
					pos.y -= deltay;
			}
			if (this->key_LEFT && pos.x >= 0) {
				this->op = true;
				this->initWithSpriteFrameName("ship_1_06.png");
				if(pos.x > this->getContentSize().width / 2 +6)
					pos.x -= deltax;
			}
			if (this->key_DOWN && this->key_LEFT) {
				this->initWithSpriteFrameName("ship_1_04.png");
			}
			if (this->key_RIGHT && pos.x <= size.width) {
				this->op = true;
				this->initWithSpriteFrameName("ship_1_20.png");
				if(pos.x <320 -  this->getContentSize().width / 2 - 6)
					pos.x += deltax;
			}
			if (this->key_DOWN && this->key_RIGHT) {
				this->initWithSpriteFrameName("ship_1_18.png");
			}
			if (this->key_SHOOT) {
				this->shoot();
			}
		}
		/*
		if (FLANKER.KEYS[this.key_BOOM]) {
			if(FLANKER.PLAYER[this._player].BOOMB > 0) {
				if(this->isAnimate){
					this->op = false;
					this->isAnimate = false;

					var animFrames = [];
					for (var i = 0; i < 47; i++) {
						animFrames[i] = cc.SpriteFrameCache.getInstance().getSpriteFrame('ship_1_' + (i + 26) + '.png');
					}
					animFrames[47] = cc.SpriteFrameCache.getInstance().getSpriteFrame("ship_1_01.png");

					var animation = cc.Animation.create(animFrames, 0.05);
					var animate = cc.Animate.create(animation);
					this.runAction(animate);

					cc.AudioEngine.getInstance().playEffect(m_boomb_start);
					setTimeout(function(){
						cc.AudioEngine.getInstance().playEffect(m_boomb_bee);
					}, 200);

					for(var i = 0; i < 16; i++ ) {
						var boom = Boomb_1.create(this._player);
						FLANKER.CONTAINER.EXPLOSIONS.push(boom);

					}

					for(var i = 0, len = FLANKER.CONTAINER.BOSS.length; i < len; i++) {
						if(FLANKER.CONTAINER.BOSS[i]._alive && FLANKER.CONTAINER.BOSS[i]._isBoss) {

							//Bomb damage
							FLANKER.CONTAINER.BOSS[i].hurt(20, this._player);
						}
					}

					for(var j = 0, plen = FLANKER.CONTAINER.ENEMIES.length; j < plen; j++) {
						if(FLANKER.CONTAINER.ENEMIES[j]._alive && !FLANKER.CONTAINER.ENEMIES[j]._isBoss) {
							FLANKER.CONTAINER.ENEMIES[j].hurt(20, this._player);
						}
					}

					setTimeout(function(ctx){
						ctx.isAnimate = true;
					}, 52 * 55, this);

					FLANKER.PLAYER[this._player].BOOMB--;
				}
			}
		}*/
			this->setPosition(pos);
	}
}


void Flight::setDelta(double dx, double dy) {
	this->dx = dx;
	this->dy = dy;
}

void Flight::setDeltaXY(double dx, double dy) {
	this->deltax = dx;
	this->deltay = dy;
}
void Flight::move(float dt)
{
	if(this->_alive &&GameController::getInstance()->g_sharedGameLayer->getState() == STATE_PLAYING)
	{
		Point pos = this->getPosition();
		if(this->isAnimate){
			if(pos.y < 480 - this->getContentSize().height / 2){
				pos.y += this->dy;
			}else{
				pos.y = 480 - this->getContentSize().height / 2;
			}
			if(pos.y > this->getContentSize().height / 2 +7){
				pos.y += this->dy;
			}else{
				pos.y = this->getContentSize().height / 2 +7;
			}
			if(pos.x > this->getContentSize().width / 2 +6){
				pos.x += this->dx;
			}else{
				pos.x = this->getContentSize().width / 2 +6;
			}

			if(pos.x < 320 -  this->getContentSize().width / 2 - 6){
				pos.x += this->dx;
			}else{
				pos.x = 320 -  this->getContentSize().width / 2 - 6;
			}
			switch(this->direction){
				case 0:
					this->initWithSpriteFrameName("ship_1_01.png");
					this->setAnchorPoint(Point(0.5,0.5));
				break;
				case 1:
				break;
				case 2:
					this->initWithSpriteFrameName("ship_1_07.png");
					this->setAnchorPoint(Point(0.5,0.7));
				break;
				case 3:
				break;
				case 4:
					this->initWithSpriteFrameName("ship_1_06.png");
				break;
				case 5:
					this->initWithSpriteFrameName("ship_1_20.png");
				break;
				case 6:
					this->initWithSpriteFrameName("ship_1_18.png");
				break;
				case 7:
					this->initWithSpriteFrameName("ship_1_15.png");
				break;
				case 8:
					this->initWithSpriteFrameName("ship_1_20.png");
				break;
				default :
				break;

			}
		}
		this->setPosition(pos);
	}
}

void Flight::shoot()
{
	if(this->dt % 7 == 0)
	{
		int offset = 13;
		Point p = this->getPosition();
		Size cs = this->getContentSize();

		//NormalBullet* bullet = new NormalBullet("ship1_b_" + std::to_string(this->_power) + ".png", p.x, p.y + 3 + cs.height * 0.3, 1, 0);

		/*if(this->_player == 0) {
			//수정필요 FLANKER.CONTAINER.PLAYER1_BULLETS.push(bullet);
			printf("");
		}*/
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/sfx/sfx_039.mp3");
	}
	this->dt++;
}

/*void Flight::lethalShoot()
{
	int offset = 13;
	Point p = this->getPosition();
	Size cs = this->getContentSize();
	//수정필요 var lethal = Lethal.getOrCreateBullet(FLANKER.PLAYER[this._player].SHIPTYPE, p.x, p.y + 3 + cs.height * 0.3, FLANKER.BULLET_SPEED.SHIP);
	if(this->_player == 0)
	{
		//수정필요 FLANKER.CONTAINER.PLAYER1_LETHAL.push(lethal);
	}
	else if(this->_player == 1)
	{
		//수정필요 FLANKER.CONTAINER.PLAYER2_LETHAL.push(lethal);
	}
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/sfx/sfx_083.mp3");
}*/

/*void Flight::initBornSprite()
{

	this->bornSprite = Sprite::createWithSpriteFrameName("1p.png");

	else if(this->_player == 1)
	{
		this->bornSprite = Sprite::createWithSpriteFrameName("2p.png");
	}
	this->bornSprite->setPosition(this->getContentSize().width / 2, 19);
	this->bornSprite->setVisible(true);
	this->addChild(this->bornSprite, 3000, 99999);
}*/


void Flight::born()
{
	this->setPosition(this->appearPosition);
	//revive effect
	this->op = false;
	this->isAnimate = false;
	this->canBeAttack = false;
	this->initWithSpriteFrameName("ship_1_09.png");

	this->setAnchorPoint(Point(0.5,0.75));
	this->runAction( Sequence::create(DelayTime::create(0.5), MoveBy::create(1, Point(0, 120)), MoveBy::create(1, Point(0, -60)), NULL));

	this->runAction(Sequence::create(DelayTime::create(0.5), Blink::create(1.5, 5), CallFunc::create( [&](){
		this->canBeAttack = true;

	}), NULL));

	this->HP = 5;
	this->_hurtColorLife = 0;


	this->runAction( Sequence::create(DelayTime::create(0.5f), CallFunc::create( [&]() {
		this->setAnchorPoint(Point(0.5, 0.5));
		this->initWithSpriteFrameName("ship_1_01.png");
	}), NULL));


	this->runAction( Sequence::create(DelayTime::create(2.3f), CallFunc::create( [&]() {
		this->isAnimate = true;
		this->op = true;
		this->_alive = true;
	}), NULL));
}

void Flight::demage()
{
	if(this->_power > 1)
	{
		this->_power--;
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/sfx/sfx_lose_power.mp3");
	}
	else
	{
		this->destroy();
	}
}

void Flight::hurt()
{
	this->destroy();
}

/*void Flight::levelUp()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/sfx/sfx_get_power.mp3");

	if(FLANKER.PLAYER[this->_player].POWER < 3)
	{
		this->_power++;
		FLANKER.PLAYER[this->_player].POWER++;
	}
}*/

Rect Flight::collideRect(Point p) {
	Size a = this->getContentSize();
	return Rect(p.x - a.width / 2 + 6, p.y - a.height / 2 + 6, a.width - 6 , a.height- 6);
}


