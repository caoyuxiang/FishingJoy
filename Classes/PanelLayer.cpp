#include "PanelLayer.h"
#include "GameScene.h"
#include "ScheduleCountDown.h"

PanelLayer::PanelLayer(void)
{

}

PanelLayer::~PanelLayer(void)
{

}
bool PanelLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	_goldCounter = GoldCounterLayer::create(0);
	this->addChild(_goldCounter);
	_goldCounter->setPosition(ccp(475, 40));//����޸�λ��

	ScheduleCountDown* countDown = ScheduleCountDown::create(this);

	_scheduleLabel = CCLabelTTF::create("55", "Thonburi", 45);//�����С
	_scheduleLabel->setColor(ccc3(241, 158, 194));
	_scheduleLabel->addChild(countDown);
	this->addChild(_scheduleLabel);
	_scheduleLabel->setPosition(ccp(750, 50));//����ʱλ��

    return true;
}

void PanelLayer::setScheduleNumber(int number)
{
	_scheduleLabel->setString(CCString::createWithFormat("%d",number)->getCString());
}

void PanelLayer::scheduleTimeUp()
{
	_scheduleLabel->setVisible(false);

	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->scheduleTimeUp();
}
