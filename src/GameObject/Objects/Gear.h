#ifndef GEAR_H
#define GEAR_H

#include "GameObject2D.h"
class Gear : public GameObject2D
{
public:
	Gear() = delete;
	Gear(const Gear&) = delete;
	const Gear& operator = (const Gear&) = delete;
	~Gear();

	Gear(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);

};

#endif GEAR_H