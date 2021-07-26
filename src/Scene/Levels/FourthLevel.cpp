#include "FourthLevel.h"
#include "Game.h"
#include "Keyboard.h"
#include "ObjectFactory.h"
#include "BackgroundFactory.h"
#include "PigFactory.h"
#include "Wood.h"
#include "MinionPig.h"
#include "SlingQueue.h"
#include "TowerControl.h"
#include "Tower3.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TimerMan.h"
FourthLevel::FourthLevel()
{
}

FourthLevel::~FourthLevel()
{
}

void FourthLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	SlingQueue::Create(3, 210.0f, 180.0f);

	// Load Background
	Rect rect = Rect((Game::GetWindowWidth() / 2.0f), (Game::GetWindowHeight() / 2.0f), Game::GetWindowWidth(), Game::GetWindowHeight());
	GameObject2D* tC = BackgroundFactory::CreateBackground(GameObjectName::Name::Space, rect);
	tC->SetCurrentAngle(MATH_PI);
	this->Add(tC);

	// Empty Ground
	rect = Rect(Game::GetWindowWidth() / 2.0f, Game::GetWindowHeight() - 695.0f, Game::GetWindowWidth(), 200.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);

	// Seesaw seat 1
	rect = Rect(750.0f, 200.0f, 70.0f, 10.0f);
	GameObject2D* pSeat1 = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	pSeat1->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	Wood* pWood = (Wood*)pSeat1;
	pWood->SetDamagable(false);
	this->Add(pSeat1);

	// Seesaw seat 2
	rect = Rect(1050.0f, 200.0f, 70.0f, 10.0f);
	GameObject2D* pSeat2 = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	pSeat2->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	pWood = (Wood*)pSeat2;
	pWood->SetDamagable(false);
	this->Add(pSeat2);

	// Seesaw platform
	rect = Rect(900.0f, 200.0f, 300.0f, 10.0f);
	GameObject2D* pPlatform = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	pPlatform->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	pWood = (Wood*)pPlatform;
	pWood->SetDamagable(false);
	this->Add(pPlatform);

	// Seesaw holder
	rect = Rect(900.0f, 150.0f, 100.0f, 10.0f);
	GameObject2D * pHolder = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	pHolder->SetOrigAngle(MATH_PI2);
	pWood = (Wood*)pHolder;
	pWood->SetDamagable(false);
	this->Add(pHolder);


	// Minion Pig 1
	rect = Rect(650.0f, 250.0f, 45.0f, 45.0f);
	tC = PigFactory::CreatePig(GameObjectName::Name::MinionPig0, rect, Rect(), true);
	MinionPig* pMPIG = (MinionPig*)tC;
	pMPIG->SetDamagable(false);
	this->Add(tC);

	// Minion Pig 2
	rect = Rect(950.0f, 250.0f, 45.0f, 45.0f);
	tC = PigFactory::CreatePig(GameObjectName::Name::MinionPig0, rect, Rect(), true);
	pMPIG = (MinionPig*)tC;
	pMPIG->SetDamagable(false);
	this->Add(tC);


	// Revolute Joint in platform center
	b2RevoluteJointDef rjdef;
	rjdef.Initialize(
		pHolder->GetBody(),
		pPlatform->GetBody(),
		pPlatform->GetBody()->GetWorldCenter() // should connect to holder, but this works too
	);
	b2Joint* mainRevolt = PhysicsManager::GetWorld()->CreateJoint(&rjdef);
	

	// Revolute Joint and gear joint in seats
	{
		// seat 1
		rjdef.Initialize(
			pPlatform->GetBody(),
			pSeat1->GetBody(),
			pSeat1->GetBody()->GetWorldCenter() 
		);
		b2Joint* seat1Joint = PhysicsManager::GetWorld()->CreateJoint(&rjdef);

		// seat 2
		rjdef.Initialize(
			pPlatform->GetBody(),
			pSeat2->GetBody(),
			pSeat2->GetBody()->GetWorldCenter()
		);
		b2Joint* seat2Joint = PhysicsManager::GetWorld()->CreateJoint(&rjdef);

		// gear joint
		b2GearJointDef gjdef;
		gjdef.bodyA = pPlatform->GetBody();
		gjdef.bodyB = pSeat1->GetBody();
		gjdef.joint1 = mainRevolt;
		gjdef.joint2 = seat1Joint;
		gjdef.ratio = 1.0f;
		PhysicsManager::GetWorld()->CreateJoint(&gjdef);

		// gear joint
		gjdef.bodyA = pPlatform->GetBody();
		gjdef.bodyB = pSeat2->GetBody();
		gjdef.joint1 = mainRevolt;
		gjdef.joint2 = seat2Joint;
		gjdef.ratio = 1.0f;
		PhysicsManager::GetWorld()->CreateJoint(&gjdef);
	}

	Tower3* pTow = new Tower3(520.0f, 120.0f,5);
	InputSystem* pSys = (InputSystem*)new TowerControl(pTow);
	InputManager::AddInputs(pSys, InputSystem::InputType::TOWER_INPUT);
}

void FourthLevel::Update()
{
	static bool rKey = false;

	if (!rKey && Keyboard::GetKeyState(AZUL_KEY::KEY_R))
	{
		SlingQueue::ReloadBirds(210.0f, 300.0f);
	}
	rKey = Keyboard::GetKeyState(AZUL_KEY::KEY_R);

	GameObjectMan::Update(0.0f);
}

void FourthLevel::Draw()
{
	GameObjectMan::Draw();
}

void FourthLevel::Clean()
{
	// destroy all joints in the scene.
	PhysicsManager::DestroyAllJoints();
	TimerMan::ClearTimerEvents();
	SlingQueue::Terminate();
	InputManager::Delete(InputSystem::InputType::TOWER_INPUT);
}

