#ifndef EGG_H
#define EGG_H

#include "GameObject2D.h"
class Egg : public GameObject2D
{
public:
	Egg() = delete;
	Egg(const Egg&) = delete;
	const Egg& operator = (const Egg&) = delete;
	~Egg();

	Egg(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle);

	virtual void Update(float t) override;
	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(CollisionObjectBox& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;

	bool impact;
	GameObject2D* blast;
};

#endif EGG_H