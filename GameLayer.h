#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"
#include "../Background.h"
#include "../GameController.h"
#include "../fighter/Flight.h"
#include "../object/Bullet.h"
#define STATE_PLAYING 0
#define STATE_GAMEOVER 1
#define STATE_CLEAR 2
#define MAX_CONTAINT_WIDTH 40
#define MAX_CONTAINT_HEIGHT 40
#define Z_PLAYER 5
#define Z_BACKGROUND 1
#define Z_ENEMY 3
#define Z_BULLET 4


USING_NS_CC;

class Flight;
class Bullet;

class GameLayer : public cocos2d::Layer
{
private:
	SpriteBatchNode* _shipBatch;
	SpriteBatchNode* _backgroundBatch;
	SpriteBatchNode* _bulletBatch;
	Background* _background;
	int _state;
	cocos2d::Label *a = NULL;
	Flight* _flight;
	Rect screenRect;
	//Label *lb;
public:
	GameLayer();

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameLayer);

	void initBackground();
	void update(float);

	int getState() const {
		return _state;
	}

	void setState(int state) {
		_state = state;
	}

	void OnAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);
	//bool OnTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event);
	void OnTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event);
	void OnTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event);

	void addBullet(Bullet* bullet);

	const Rect& getScreenRect() const {
		return screenRect;
	}

	void setScreenRect(const Rect& screenRect) {
		this->screenRect = screenRect;
	}

	Flight*& getFlight() {
		return _flight;
	}

	void setFlight(Flight*& flight) {
		_flight = flight;
	}
};

#endif
