#include "ThirdLevel.h"
#include "Game.h"
#include "BackgroundFactory.h"
#include "BirdFactory.h"
#include "FilterCategory.h"
#include "ObjectFactory.h"
#include "PigFactory.h"
#include "InputManager.h"
#include "DragInput.h"
#include "LanderInput.h"
#include "ImpulseInput.h"
#include "KingPig.h"
#include "TimerMan.h"
ThirdLevel::ThirdLevel()
{
}

ThirdLevel::~ThirdLevel()
{
}

void ThirdLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	// Load Background
	Rect rect = Rect((Game::GetWindowWidth() / 2.0f), (Game::GetWindowHeight() / 2.0f), Game::GetWindowWidth(), Game::GetWindowHeight());
	GameObject2D* tC = BackgroundFactory::CreateBackground(GameObjectName::Name::Background, rect);
	this->Add(tC);

	// Load Birds
	// RedBird0
	rect = Rect(200.0f, 555.0f, 50.0f, 50.0f);
	tC = BirdFactory::CreateBird(GameObjectName::Name::RedBird0, rect, Rect(), true);
	this->Add(tC);
	tC->SetDebugColor(Color::Type::Black);
	tC->SetDrawDebug(true);
	tC->SetOrigAngle(0.7f);
	b2Fixture* editFixture = tC->GetBody()->GetFixtureList();
	b2Filter newFilter;
	newFilter.categoryBits = FilterCategory::PLAYER;
	newFilter.maskBits = FilterCategory::BLOCKTYPE1;
	editFixture->SetFilterData(newFilter);
	editFixture->SetDensity(10.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.80f);

	// BlueBird0
	rect = Rect(310.0f, 755.0f, 25.0f, 25.0f);
	tC = BirdFactory::CreateBird(GameObjectName::Name::BlueBird0, rect, Rect(), true);
	this->Add(tC);
	tC->SetDrawDebug(true);
	editFixture = tC->GetBody()->GetFixtureList();
	editFixture->SetDensity(10.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.80f);

	// WhiteBird0
	rect = Rect(910.0f, 755.0f, 35.0f, 35.0f);
	Rect debugRect = Rect(0.0f, 0.0f, 40.0f, 40.0f);
	tC = BirdFactory::CreateBird(GameObjectName::Name::WhiteBird0, rect, debugRect, true);
	this->Add(tC);
	tC->SetDrawDebug(true);
	tC->SetDebugColor(Color::Type::Green);
	editFixture = tC->GetBody()->GetFixtureList();
	newFilter.categoryBits = FilterCategory::PLAYER;
	newFilter.maskBits = FilterCategory::BLOCKTYPE1;
	editFixture->SetDensity(5.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.80f);
	editFixture->SetFilterData(newFilter);

	// YellowBird0
	rect = Rect(850.0f, 700.0f, 35.0f, 35.0f);
	tC = BirdFactory::CreateBird(GameObjectName::Name::YellowBird0, rect, Rect(), true);
	this->Add(tC);
	editFixture = tC->GetBody()->GetFixtureList();
	editFixture->SetDensity(10.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.80f);

	// GreenBird0
	rect = Rect(550.0f, 655.0f, 35.0f, 35.0f);
	debugRect = Rect(0.0f, 0.0f, 40.0f, 40.0f);
	tC = BirdFactory::CreateBird(GameObjectName::Name::GreenBird0, rect, debugRect, true);
	this->Add(tC);
	tC->SetDrawDebug(true);
	editFixture = tC->GetBody()->GetFixtureList();
	editFixture->SetDensity(10.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.80f);

	// BigBird0
	rect = Rect(215.0f, 665.0f, 45.0f, 45.0f);
	tC = BirdFactory::CreateBird(GameObjectName::Name::BigBird0, rect, Rect(), true);
	this->Add(tC);
	editFixture = tC->GetBody()->GetFixtureList();
	editFixture->SetDensity(30.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.80f);


	// Box Fixture 4
	rect = Rect(200.0f, 565.0f, 80.0f, 80.0f);
	GameObject2D* tC2 = ObjectFactory::CreateObject(GameObjectName::Name::WoodSquare0, rect, Rect(), false);
	this->Add(tC2);
	tC->GetPhysicsObject()->CreateShapeAndFixture(tC2);
	editFixture = tC->GetBody()->GetFixtureList();
	editFixture->SetDensity(1.0f);
	tC2->SetFixture(editFixture, 0.0f, 0.0f, 0.0f);

	////-------------------------------------------------------------------------

	InputSystem* pSystem = (InputSystem*)new LanderInput(tC);
	InputManager::AddInputs(pSystem, InputSystem::InputType::LANDER_INPUT);

	DragInput* pSys = new DragInput(Game::GetWindowHeight());
	InputManager::AddInputs((InputSystem*)pSys, InputSystem::InputType::DRAG_INPUT);
	pSys->AddToTestList(tC);


	////-------------------------------------------------------------------------

	// BombBird0
	rect = Rect(250.0f, 455.0f, 45.0f, 45.0f);
	tC = BirdFactory::CreateBird(GameObjectName::Name::BombBird0, rect, Rect(), true);
	this->Add(tC);
	editFixture = tC->GetBody()->GetFixtureList();
	editFixture->SetDensity(10.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.80f);

	// Empty Ground
	rect = Rect(Game::GetWindowWidth() / 2.0f, 115.0f, Game::GetWindowWidth(), 200.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);
	tC->SetDebugColor(Color::Type::Red);
	tC->SetDrawDebug(true);
	editFixture = tC->GetBody()->GetFixtureList();
	newFilter.categoryBits = FilterCategory::BLOCKTYPE1;
	newFilter.maskBits = FilterCategory::PLAYER | FilterCategory::PIG;
	editFixture->SetFilterData(newFilter);

	// Empty Ground Top
	rect = Rect(Game::GetWindowWidth() / 2.0f, 890.0f, Game::GetWindowWidth(), 20.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);
	tC->SetDebugColor(Color::Type::Red);
	tC->SetDrawDebug(true);
	editFixture = tC->GetBody()->GetFixtureList();
	newFilter.categoryBits = FilterCategory::BLOCKTYPE1;
	newFilter.maskBits = FilterCategory::PLAYER | FilterCategory::PIG;
	editFixture->SetFilterData(newFilter);

	// Empty Ground Left
	rect = Rect(10.0f, Game::GetWindowHeight() / 2.0f, 20.0f, Game::GetWindowHeight());
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);
	tC->SetDebugColor(Color::Type::Red);
	tC->SetDrawDebug(true);
	editFixture = tC->GetBody()->GetFixtureList();
	newFilter.categoryBits = FilterCategory::BLOCKTYPE1;
	newFilter.maskBits = FilterCategory::PLAYER | FilterCategory::PIG;
	editFixture->SetFilterData(newFilter);

	// Empty Ground Right
	rect = Rect(1270.0f, Game::GetWindowHeight() / 2.0f, 20.0f, Game::GetWindowHeight());
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);
	tC->SetDebugColor(Color::Type::Red);
	tC->SetDrawDebug(true);
	editFixture = tC->GetBody()->GetFixtureList();
	newFilter.categoryBits = FilterCategory::BLOCKTYPE1;
	newFilter.maskBits = FilterCategory::PLAYER | FilterCategory::PIG;
	editFixture->SetFilterData(newFilter);

	// MinionPig0
	rect = Rect(1100.0f, 565.0f, 35.0f, 35.0f);
	tC = PigFactory::CreatePig(GameObjectName::Name::MinionPig0, rect, Rect(), true);
	this->Add(tC);
	editFixture = tC->GetBody()->GetFixtureList();
	editFixture->SetDensity(10.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.80f);

	// CorporalPig0
	rect = Rect(1100.0f, 365.0f, 55.0f, 55.0f);
	tC = PigFactory::CreatePig(GameObjectName::Name::CorporalPig0, rect, Rect(), true);
	this->Add(tC);
	tC->SetDebugColor(Color::Type::Blue);
	tC->SetDrawDebug(true);
	editFixture = tC->GetBody()->GetFixtureList();
	editFixture->SetDensity(10.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.80f);

	// KingPig0
	rect = Rect(1100.0f, 765.0f, 65.0f, 65.0f);
	tC = PigFactory::CreatePig(GameObjectName::Name::KingPig0, rect, Rect(), true);
	KingPig* pKing = (KingPig*)tC;
	pKing->SetDamagable(false);
	this->Add(tC);
	editFixture = tC->GetBody()->GetFixtureList();
	newFilter.categoryBits = FilterCategory::PIG;
	newFilter.maskBits = FilterCategory::BLOCKTYPE1;
	editFixture->SetDensity(10.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.80f);
	editFixture->SetFilterData(newFilter);

	////-------------------------------------------------------------------------
	// for drag input
	pSys->AddToTestList(tC);

	ImpulseInput* pSys2 = new ImpulseInput(Game::GetWindowHeight());
	InputManager::AddInputs((InputSystem*)pSys2, InputSystem::InputType::IMPULSE_INPUT);
	pSys2->AddToTestList(tC);

	////-------------------------------------------------------------------------

	// WoodPlatform0
	rect = Rect(200.0f, 355.0f, 135.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	this->Add(tC);
	tC->SetDrawDebug(true);
	tC->SetOrigAngle(-0.3f);
	tC->SetDebugColor(Color::Type::Green);
	editFixture = tC->GetBody()->GetFixtureList();
	newFilter.categoryBits = FilterCategory::BLOCKTYPE1;
	newFilter.maskBits = FilterCategory::PLAYER | FilterCategory::PIG;
	editFixture->SetFilterData(newFilter);

	// WoodPlatform01
	rect = Rect(200.0f, 555.0f, 135.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	this->Add(tC);
	tC->SetDrawDebug(true);
	tC->SetOrigAngle(0.0f);
	tC->SetDebugColor(Color::Type::Green);

	// WoodPlatform02
	rect = Rect(170.0f, 555.0f, 435.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	this->Add(tC);
	tC->SetDrawDebug(true);
	tC->SetOrigAngle(1.5f);
	tC->SetDebugColor(Color::Type::Black);

	// WoodEquiTriangle0
	rect = Rect(380.0f, 555.0f, 45.0f, 45.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodEquiTriangle0, rect, Rect(), true);
	this->Add(tC);
	tC->SetScale(2.5, 2.5f);
	tC->SetOrigAngle(-0.5f);

	// GlassCircle0
	rect = Rect(650.0f, 455.0f, 45.0f, 45.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::GlassCircle0, rect, Rect(), true);
	this->Add(tC);
	tC->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	editFixture = tC->GetBody()->GetFixtureList();
	editFixture->SetDensity(10.0f);
	editFixture->SetFriction(0.3f);
	editFixture->SetRestitution(0.50f);

	// GlassPlatform0
	rect = Rect(390.0f, 855.0f, 135.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, rect, Rect(), true);
	this->Add(tC);
	tC->SetDrawDebug(true);
	tC->SetDebugColor(Color::Type::Red);

	// GlassPlatform01
	rect = Rect(900.0f, 855.0f, 555.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, rect, Rect(), true);
	this->Add(tC);
	tC->SetDrawDebug(true);
	tC->SetDebugColor(Color::Type::Red);

	// StonePlatform0
	rect = Rect(350.0f, 255.0f, 135.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);

	// StonePlatform01
	rect = Rect(900.0f, 255.0f, 555.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);
}

void ThirdLevel::Update()
{
	GameObjectMan::Update(0.0f);
}

void ThirdLevel::Draw()
{
	GameObjectMan::Draw();
}

void ThirdLevel::Clean()
{
	TimerMan::ClearTimerEvents();
	InputManager::Delete(InputSystem::InputType::DRAG_INPUT);
	InputManager::Delete(InputSystem::InputType::LANDER_INPUT);
	InputManager::Delete(InputSystem::InputType::IMPULSE_INPUT);
}
