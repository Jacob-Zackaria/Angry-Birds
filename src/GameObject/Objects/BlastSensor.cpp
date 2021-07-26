#include "BlastSensor.h"
#include "ContactAction.h"
BlastSensor::~BlastSensor()
{
}

BlastSensor::BlastSensor(GameObjectName::Name name, GraphicsObject_Circle* graphicsObject_Circle)
	:
	GameObject2D(name, nullptr, graphicsObject_Circle)
{
}

void BlastSensor::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void BlastSensor::CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void BlastSensor::CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void BlastSensor::CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void BlastSensor::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void BlastSensor::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}


