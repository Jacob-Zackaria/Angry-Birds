#ifndef BLAST_SENSOR_H
#define BLAST_SENSOR_H

#include "GameObject2D.h"

class BlastSensor : public GameObject2D
{
public:
	BlastSensor() = delete;
	BlastSensor(const BlastSensor&) = delete;
	const BlastSensor& operator = (const BlastSensor&) = delete;
	~BlastSensor();
	BlastSensor(GameObjectName::Name name, GraphicsObject_Circle* graphicsObject_Cirlce);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Wood&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(Glass&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(Stone&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(MinionPig&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(KingPig&, b2Contact*, const b2ContactImpulse*) override;

};

#endif BLAST_SENSOR_H