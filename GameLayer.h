#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"
#include "../Background.h"
#include "../GameController.h"
#define STATE_PLAYING 0
#define STATE_GAMEOVER 1
#define STATE_CLEAR 2
#define MAX_CONTAINT_WIDTH 40
#define MAX_CONTAINT_HEIGHT 40



USING_NS_CC;

class GameLayer : public cocos2d::Layer
{
private:
	SpriteBatchNode* _shipBatch;
	SpriteBatchNode* _backgroundBatch;
	Background* _background;
	int _state;
	cocos2d::Label *a = NULL;
	bool key_UP, key_DOWN, key_LEFT, key_RIGHT;
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

	bool isKeyDown() const {
		return key_DOWN;
	}

	bool isKeyLeft() const {
		return key_LEFT;
	}

	bool isKeyRight() const {
		return key_RIGHT;
	}

	bool isKeyUp() const {
		return key_UP;
	}
};

#endif
