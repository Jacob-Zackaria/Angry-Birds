#include "SecondLevel.h"
#include "Game.h"
#include "ObjectFactory.h"
#include "BackgroundFactory.h"
#include "BirdFactory.h"
#include "InputManager.h"
#include "SlingQueue.h"
#include "TowerControl.h"
#include "Tower2.h"
#include "TimerMan.h"
SecondLevel::SecondLevel()
{
}

SecondLevel::~SecondLevel()
{
}


void SecondLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, 2.0f));

	SlingQueue::Create(4, 210.0f, 75.0f);

	// Load Background
	Rect rect = Rect((Game::GetWindowWidth() / 2.0f), (Game::GetWindowHeight() / 2.0f), Game::GetWindowWidth(), Game::GetWindowHeight());
	GameObject2D* tC = BackgroundFactory::CreateBackground(GameObjectName::Name::Space2, rect);
	this->Add(tC);

	// Empty Ground
	rect = Rect(Game::GetWindowWidth() / 2.0f, Game::GetWindowHeight() - 180.0f, Game::GetWindowWidth(), 100.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);

	// draw ground
	rect = Rect(130.0f, 5.0f, 250.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), false);
	this->Add(tC);


	Tower2* pTow = new Tower2(720.0f, 500.0f, 3);
	InputSystem* pSys = (InputSystem*)new TowerControl(pTow);
	InputManager::AddInputs(pSys, InputSystem::InputType::TOWER_INPUT);

}

void SecondLevel::Update()
{
	static bool rKey = false;

	if (!rKey && Keyboard::GetKeyState(AZUL_KEY::KEY_R))
	{
		SlingQueue::ReloadBirds(210.0f, 75.0f);
	}
	rKey = Keyboard::GetKeyState(AZUL_KEY::KEY_R);

	GameObjectMan::Update(0.0f);
}

void SecondLevel::Draw()
{
	GameObjectMan::Draw();
}

void SecondLevel::Clean()
{
	TimerMan::ClearTimerEvents();
	SlingQueue::Terminate();
	InputManager::Delete(InputSystem::InputType::TOWER_INPUT);
}
