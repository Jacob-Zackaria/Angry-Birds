#include "FirstLevel.h"
#include "Game.h"
#include "ObjectFactory.h"
#include "BackgroundFactory.h"
#include "InputManager.h"
#include "SlingQueue.h"
#include "TowerControl.h"
#include "Tower1.h"
#include "TimerMan.h"
FirstLevel::FirstLevel()
{
}

FirstLevel::~FirstLevel()
{
}


void FirstLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	SlingQueue::Create(3, 210.0f, 300.0f);

	// Load Background
	Rect rect = Rect((Game::GetWindowWidth() / 2.0f), (Game::GetWindowHeight() / 2.0f), Game::GetWindowWidth(), Game::GetWindowHeight());
	GameObject2D* tC = BackgroundFactory::CreateBackground(GameObjectName::Name::Background, rect);
	this->Add(tC);

	// Empty Ground
	rect = Rect(Game::GetWindowWidth() / 2.0f, Game::GetWindowHeight() - 595.0f, Game::GetWindowWidth(), 200.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);

	Tower1* pTow = new Tower1(720.0f, 229.0f, 3);
	InputSystem* pSys = (InputSystem*)new TowerControl(pTow);
	InputManager::AddInputs(pSys, InputSystem::InputType::TOWER_INPUT);

}

void FirstLevel::Update()
{

	static bool rKey = false;

	if (!rKey && Keyboard::GetKeyState(AZUL_KEY::KEY_R))
	{
		SlingQueue::ReloadBirds(210.0f, 300.0f);
	}
	rKey = Keyboard::GetKeyState(AZUL_KEY::KEY_R);

	GameObjectMan::Update(0.0f);

}

void FirstLevel::Draw()
{
	GameObjectMan::Draw();
}

void FirstLevel::Clean()
{
	TimerMan::ClearTimerEvents();
	SlingQueue::Terminate();
	InputManager::Delete(InputSystem::InputType::TOWER_INPUT);
}
