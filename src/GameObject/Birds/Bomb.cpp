#include "Bomb.h"
#include "ContactAction.h"
#include "BirdDeath.h"
#include "TimerMan.h"
#include "InputManager.h"
#include "ObjectFactory.h"
#include "SceneManager.h"
#include "TimerMan.h"
#include "BombExplosion.h"
#include "SmokeDeletion.h"
#include "EffectFactory.h"
#include "PixelToMeter.h"
Bomb::~Bomb()
{
	delete this->newAnim;
}

Bomb::Bomb(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	Bird(name, graphicsObject, graphicsObject_Circle), exploded(false), blast(nullptr)
{
	this->health = 300.0f;

	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::BombBird1, 250.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::BombBird2, 100.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::BombBird3, 50.0f, graphicsObject->GetRect());
}

void Bomb::Update(float t)
{
	if (!exploded)
	{
		if (!this->GetBody()->IsAwake() && !this->markedDead)
		{
			// if impact and body is not awake, kill bird after 3 sec.
			TimerMan::AddEvent(3.0f, new BirdDeath(this));
			this->markedDead = true;
		}

		// blast effect
		if ((this->bState == BirdState::FLYING) && (InputManager::GetMouseState() == InputManager::MouseState::LEFT))
		{
			exploded = true;

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
		
	}
	else
	{
		b2CircleShape* circleShape = (b2CircleShape*)blast->GetBody()->GetFixtureList()->GetShape();
		
		blast->SetScale(blast->GetScaleX() + 1.0f, blast->GetScaleY() + 1.0f);
		circleShape->m_radius = PixelToMeter(blast->GetScaleX() * 3.5f);
	}

	// call update on base bird
	Bird::Update(t);
}

void Bomb::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void Bomb::CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void Bomb::CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void Bomb::CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void Bomb::CollideVisit(CollisionObjectBox& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	pContact;
	pImpulse;
	other;
}

void Bomb::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void Bomb::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void Bomb::ReduceHealth(const float newVal)
{
	if (this->damagable && !this->markedDead)
	{
		this->health -= newVal;
		if (this->health <= 0.0f)
		{
			this->health = 0.0f;
			TimerMan::AddEvent(3.0f, new BirdDeath(this));

			this->markedDead = true;

		}
		else if (this->newAnim->GetLink())
		{
			if (this->health < this->newAnim->GetHealthVal())
			{
				this->SwapImage(this->newAnim->GetSprite());
				this->newAnim->SetNextLink();
			}
		}
	}
}
