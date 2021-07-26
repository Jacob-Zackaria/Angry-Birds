#include "Egg.h"
#include "ContactAction.h"
#include "SmokeDeletion.h"
#include "EffectFactory.h"
#include "TimerMan.h"
#include "ObjectFactory.h"
#include "SceneManager.h"
#include "BombExplosion.h"
#include "PixelToMeter.h"
Egg::~Egg()
{
}

Egg::Egg(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Circle), impact(false), blast(nullptr)
{
}

void Egg::Update(float t)
{
	if (impact && this->blast == nullptr)
	{
		
		this->SetDrawSprite(false);
		this->GetBody()->SetActive(false);

		SmokeDeletion* newEvent = new SmokeDeletion(EffectFactory::CreateEffect(GameObjectName::Name::Smoke, Rect(this->GetPosX(), this->GetPosY(), 35.0f, 35.0f)));
		TimerMan::AddEvent(0.1f, newEvent);

		blast = ObjectFactory::CreateObject(GameObjectName::Name::BlastSensor, Rect(), Rect(this->GetPosX(), this->GetPosY(), 10.0f, 10.0f), true);
		blast->GetBody()->SetType(b2BodyType::b2_kinematicBody);
		blast->GetBody()->GetFixtureList()->SetSensor(true);
		blast->SetDrawDebug(true);
		SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), blast);

		TimerMan::AddEvent(0.2f, new BombExplosion(this, blast));


	}
	else if (this->blast != nullptr)
	{
		b2CircleShape* circleShape = (b2CircleShape*)blast->GetBody()->GetFixtureList()->GetShape();

		blast->SetScale(blast->GetScaleX() + 1.0f, blast->GetScaleY() + 1.0f);
		circleShape->m_radius = PixelToMeter(blast->GetScaleX() * 3.5f);
	}

	// call update on base bird
	GameObject2D::Update(t);
}

void Egg::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void Egg::CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void Egg::CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void Egg::CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void Egg::CollideVisit(CollisionObjectBox& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void Egg::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void Egg::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}