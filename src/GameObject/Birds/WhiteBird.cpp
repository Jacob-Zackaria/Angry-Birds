#include "WhiteBird.h"
#include "ContactAction.h"
#include "BirdDeath.h"
#include "TimerMan.h"
#include "InputManager.h"
#include "BirdFactory.h"
#include "SceneManager.h"
WhiteBird::~WhiteBird()
{
	delete this->newAnim;
}

WhiteBird::WhiteBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	Bird(name, graphicsObject, graphicsObject_Circle), dropped(false)
{
	this->health = 300.0f;

	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::WhiteBird1, 250.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::WhiteBird3, 100.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::WhiteBird5, 50.0f, graphicsObject->GetRect());
}

void WhiteBird::Update(float t)
{
	if (!this->GetBody()->IsAwake() && !this->markedDead)
	{
		// if impact and body is not awake, kill bird after 3 sec.
		TimerMan::AddEvent(3.0f, new BirdDeath(this));
		this->markedDead = true;
	}

	// blast effect
	if ((this->bState == BirdState::FLYING) && !dropped && (InputManager::GetMouseState() == InputManager::MouseState::LEFT))
	{
		dropped = true;

		GameObject2D* droppedEgg = BirdFactory::CreateBird(GameObjectName::Name::Egg, Rect(this->GetPosX(), this->GetPosY(), 20.0f, 30.0f), Rect(), true);
		SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), droppedEgg);

		// apply an impulse to up vector.
		b2Vec2 velocity(2.0f, 7.0f);

		this->GetBody()->ApplyLinearImpulse(10.0f * velocity, this->GetBody()->GetWorldCenter(), true);
	}


	// call update on base bird
	Bird::Update(t);
}

void WhiteBird::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void WhiteBird::CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void WhiteBird::CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void WhiteBird::CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void WhiteBird::CollideVisit(CollisionObjectBox& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	pContact;
	pImpulse;
	other;
}

void WhiteBird::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void WhiteBird::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void WhiteBird::ReduceHealth(const float newVal)
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
