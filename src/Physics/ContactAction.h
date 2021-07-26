#ifndef CONTACT_ACTION_H
#define CONTACT_ACTION_H

struct b2ContactImpulse;
class b2Contact;
class Wood;
class RedBird;
class YellowBird;
class WhiteBird;
class BlueBird;
class Stone;
class Glass;
class KingPig;
class BigBird;
class MinionPig;
class Bomb;
class Egg;
class CollisionObjectBox;
class BlastSensor;

class ContactAction
{
public:
	static void ContactPair(RedBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(BigBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(YellowBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(BlueBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(WhiteBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(Bomb& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Bomb& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Bomb& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Bomb& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Bomb& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(Egg& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& bird, CollisionObjectBox& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(MinionPig& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(MinionPig& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(MinionPig& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(MinionPig& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(MinionPig& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(KingPig& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(KingPig& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(KingPig& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(KingPig& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(KingPig& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(BlastSensor& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlastSensor& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlastSensor& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlastSensor& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlastSensor& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

private:
	static void ShowBang(b2Contact* pContact);
};


#endif CONTACT_ACTION_H