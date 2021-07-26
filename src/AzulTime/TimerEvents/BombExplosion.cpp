#include "BombExplosion.h"
#include "SceneManager.h"
#include "TimerMan.h"
BombExplosion::BombExplosion(GameObject2D* pNewObj, GameObject2D* explosion)
	:
	pObj(pNewObj),
	pExp(explosion)
{
}

void BombExplosion::Execute(float currTime)
{
	currTime;
	TimerMan::DeleteEvent(TimerEvent::Name::TRAIL_EVENT);

	

	SceneManager::DeleteSceneObject(SceneManager::GetCurrentScene(), pObj);
	SceneManager::DeleteSceneObject(SceneManager::GetCurrentScene(), pExp);
}

BombExplosion::~BombExplosion()
{
}
