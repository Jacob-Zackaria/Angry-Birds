#ifndef WHITE_BIRD_H
#define WHITE_BIRD_H

#include "Bird.h"
#include "GameObjectCharacteristics.h"
class WhiteBird : public Bird, public GameObjectCharacteristics
{
public:
	WhiteBird() = delete;
	WhiteBird(const WhiteBird&) = delete;
	const WhiteBird& operator = (const WhiteBird&) = delete;
	virtual ~WhiteBird();
	WhiteBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);

	virtual void Update(float t) override;
	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(CollisionObjectBox& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;

	virtual void ReduceHealth(const float newVal) override;

	bool dropped;
};

#endif WHITE_BIRD_H