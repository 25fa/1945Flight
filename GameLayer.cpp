#include "GameLayer.h"
#include "../fighter/Flight.h"
//#include "../fighter/F117.h"
#include <string>

Scene* GameLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = GameLayer::create();

	scene->addChild(layer);

	return scene;
}

GameLayer::GameLayer()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/ship1.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/ship3.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/background.plist");

		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/ship1.plist");
	// cache background
	auto tmpBackground = TextureCache::getInstance()->addImage("images/background.png");
	_backgroundBatch = SpriteBatchNode::createWithTexture(tmpBackground);
	this->addChild(_backgroundBatch);

	// cache F22
	auto tmpShip = TextureCache::getInstance()->addImage("images/ship1.png");
	_shipBatch = SpriteBatchNode::createWithTexture(tmpShip);
	this->addChild(_shipBatch);

	auto tmpBullet = TextureCache::getInstance()->addImage("images/s1enemy.png");
	_bulletBatch = SpriteBatchNode::createWithTexture(tmpBullet);
	this->addChild(_bulletBatch, 4);

	Size winSize = Director::getInstance()->getWinSize();
	this->screenRect = Rect(0, 0, winSize.width, winSize.height);

/*	lb = Label::create("", "arial", 50);
	lb->setAnchorPoint(ccp(0.5, 0.5));
	lb->setPosition(Point(100, 100));
	this->addChild(lb, 10);*/


	// cache F117
	//tmpShip = TextureCache::getInstance()->addImage("images/ship3.png");
	//_shipBatch = SpriteBatchNode::createWithTexture(tmpShip);
	//this->addChild(_shipBatch);
}

bool GameLayer::init()
{
	if(!Layer::init())
	{
		return false;
	}

	GameController::getInstance()->g_sharedGameLayer = this;

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/sfx/sfx_006.mp3", false);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/bg/bg_stage1.mp3", true);

	initBackground();
	this->scheduleUpdate();

	Device::setAccelerometerEnabled(true);
	auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(GameLayer::OnAcceleration, this));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto listener_touch = EventListenerTouchOneByOne::create();
	listener_touch->setSwallowTouches(true);
//	listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
	listener_touch->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this);
	listener_touch->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_touch, this);

	_flight = new Flight();
	this->addChild(_flight, 4);



	//auto f117 = new F117();
	//this->addChild(f117);


	return true;
}

void GameLayer::OnAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event)
{// x : -0.25 ~ 0.25	y : Down : -0.70 ~ -30 : Up
	double dx, dy;
	if(acc->x < -0.15)
	{

		//왼쪽
		_flight->setKeyLeft(true);
		_flight->setKeyRight(false);

	}
	else if(acc->x > 0.15)
	{
		//오른쪽
		_flight->setKeyLeft(false);
		_flight->setKeyRight(true);

	}
	else
	{
		//평지
		_flight->setKeyLeft(false);
		_flight->setKeyRight(false);

	}

	if(acc->y < -0.5)
	{
		//아래로
		_flight->setKeyUp(false);
		_flight->setKeyDown(true);

	}
	else if(acc->y > -0.5)
	{
		//위로
		_flight->setKeyUp(true);
		_flight->setKeyDown(false);

	}
	else
	{
		//평지
		_flight->setKeyUp(false);
		_flight->setKeyDown(false);

	}
	dx = abs(acc->x) * 7.2f;
	dy = abs(-0.5f - acc->y) * 8.0f;

	_flight->setDeltaXY(dx, dy);
	//std::to_string(str + str1);
	//lb->setString(str + str1);
}

void GameLayer::OnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	_flight->setKeyShoot(false);
	_flight->setKeyBoom(false);

}
void GameLayer::OnTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	Point GetPos = touch->getLocation();
	if(GetPos.x < 160)
	{
		_flight->setKeyBoom(true);
		_flight->setKeyShoot(false);
		//폭탄
	}
	else if(_flight->isKeyBoom() == false && GetPos.x >= 160)
	{
		_flight->setKeyShoot(true);

		//촐알
	}
}

void GameLayer::addBullet(Bullet* bullet)
{
	this->_bulletBatch->addChild(bullet, Z_BULLET);
}
void GameLayer::update(float dt)
{

}

void GameLayer::initBackground()
{
	_background = Background::create("s1_1.png");
	this->addChild(_background, 1);
}
