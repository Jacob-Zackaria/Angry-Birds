#include "BlueBird.h"
#include "ContactAction.h"
#include "BirdDeath.h"
#include "TimerMan.h"
#include "BirdFactory.h"
#include "InputManager.h"
#include "SceneManager.h"
BlueBird::~BlueBird()
{
	delete this->newAnim;
}

BlueBird::BlueBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	Bird(name, graphicsObject, graphicsObject_Circle), punchMode(false)
{
	this->health = 200.0f;

	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::BlueBird1, 150.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::BlueBird2, 100.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::BlueBird3, 50.0f, graphicsObject->GetRect());
}

void BlueBird::Update(float t)
{
	if (!this->GetBody()->IsAwake() && !this->markedDead)
	{
		// if impact and body is not awake, kill bird after 3 sec.
		TimerMan::AddEvent(3.0f, new BirdDeath(this));
		this->markedDead = true;
	}

	// Punch through effect
	if ((this->bState == BirdState::FLYING) && (!this->punchMode) && (InputManager::GetMouseState() == InputManager::MouseState::LEFT))
	{
		this->punchMode = true;

		Rect newRect = ((GraphicsObject_Sprite*)this->getGraphicsObject())->GetRect();
		newRect.x = this->GetPosX();
		newRect.y = this->GetPosY();

		GameObject2D* newBird1 = BirdFactory::CreateBird(GameObjectName::Name::BlueBird0, newRect, Rect(), true);
		SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), newBird1);

		GameObject2D* newBird2 = BirdFactory::CreateBird(GameObjectName::Name::BlueBird0, newRect, Rect(), true);
		SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), newBird2);

		b2Vec2 velocity = this->GetBody()->GetLinearVelocity();
		float mag = velocity.Length();
		newBird1->GetBody()->ApplyLinearImpulse(mag * velocity, newBird1->GetBody()->GetWorldCenter(), true);
		newBird2->GetBody()->ApplyLinearImpulse(mag * velocity, newBird2->GetBody()->GetWorldCenter(), true);
	}


	// call update on base bird
	Bird::Update(t);
}

void BlueBird::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void BlueBird::CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void BlueBird::CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void BlueBird::CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void BlueBird::CollideVisit(CollisionObjectBox& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	pContact;
	pImpulse;
	other;
}

void BlueBird::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void BlueBird::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void BlueBird::ReduceHealth(const float newVal)
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

