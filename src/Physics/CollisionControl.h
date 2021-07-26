#ifndef COLLISION_CONTROL_H
#define COLLISION_CONTROL_H

class GameObject2D;
class b2Contact;
struct b2ContactImpulse;

class Wood;
class RedBird;
class YellowBird;
class WhiteBird;
class BlueBird;
class Bomb;
class Stone;
class Glass;
class Egg;
class BlastSensor;
class BigBird;
class MinionPig;
class KingPig;
class CollisionObjectBox;
class CollisionObjectTri;
class TerrainSegment;
class FeatherYellow;
class FeatherRed;
class FeatherBlack;
class FeatherBlue;
class FeatherGreen;
class FeatherWhite;
class TrailSmoke;
class Projector;
class CircleParticles;

class CollisionControl
{
public:
	CollisionControl();
	CollisionControl(const CollisionControl&) = delete;
	const CollisionControl& operator = (const CollisionControl&) = delete;
	virtual ~CollisionControl();

	virtual void CollideAccept(GameObject2D&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(Wood&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(YellowBird&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(WhiteBird&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(BlueBird&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(Bomb&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(Stone&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(Glass&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(CollisionObjectBox&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(MinionPig&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(KingPig&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(TerrainSegment&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(CollisionObjectTri&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(FeatherYellow&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(FeatherRed&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(FeatherBlack&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(FeatherBlue&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(FeatherGreen&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(FeatherWhite&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(TrailSmoke&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(Projector&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(CircleParticles&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(BlastSensor&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(Egg&, b2Contact*, const b2ContactImpulse*);
	virtual void CollideVisit(BigBird&, b2Contact*, const b2ContactImpulse*);
};


#endif COLLISION_CONTROL_H