#ifndef BOMB_EXPLOSION_H
#define BOMB_EXPLOSION_H

#include "GameObject2D.h"
#include "TimerEvent.h"
class BombExplosion : public TimerEvent
{
public:

	BombExplosion(GameObject2D* pNewObj, GameObject2D* explosion);
	virtual void Execute(float currTime) override;
	virtual ~BombExplosion();

private:
	GameObject2D* pObj;
	GameObject2D* pExp;

};


#endif BOMB_EXPLOSION_H