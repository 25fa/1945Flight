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

	// cache background
	auto tmpBackground = TextureCache::getInstance()->addImage("images/background.png");
	_backgroundBatch = SpriteBatchNode::createWithTexture(tmpBackground);
	this->addChild(_backgroundBatch);

	// cache F22
	auto tmpShip = TextureCache::getInstance()->addImage("images/ship1.png");
	_shipBatch = SpriteBatchNode::createWithTexture(tmpShip);
	this->addChild(_shipBatch);




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

x

	initBackground();
	this->scheduleUpdate();

	Device::setAccelerometerEnabled(true);
	auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(GameLayer::OnAcceleration, this));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	auto f22 = new Flight();
	this->addChild(f22, 4);

	//auto f117 = new F117();
	//this->addChild(f117);


	return true;
}

void GameLayer::OnAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event)
{// x : -0.25 ~ 0.25	y : Down : -0.70 ~ -30 : Up

	if(acc->x < -0.25)
	{
		//왼쪽
		this->key_LEFT = true;
		this->key_RIGHT = false;
	}
	else if(acc->x > 0.25)
	{
		//오른쪽
		this->key_LEFT = false;
		this->key_RIGHT = true;
	}
	else
	{
		//평지
		this->key_LEFT = false;
		this->key_RIGHT = false;
	}

	if(acc->y < -0.75)
	{
		//아래로
		this->key_UP = false;
		this->key_DOWN = true;
	}
	else if(acc->y > -0.3)
	{
		//위로
		this->key_UP = true;
		this->key_DOWN = false;
	}
	else
	{
		//평지
		this->key_UP = false;
		this->key_DOWN = false;
	}

}

void GameLayer::update(float dt)
{

}

void GameLayer::initBackground()
{
	_background = Background::create("s1_1.png");
	this->addChild(_background, 1);
}
