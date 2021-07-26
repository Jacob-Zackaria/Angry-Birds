#include "ContactAction.h"
#include "Box2D.h"
#include "Wood.h"
#include "Stone.h"
#include "Glass.h"
#include "Game.h"
#include "MinionPig.h"
#include "WhiteBird.h"
#include "KingPig.h"
#include "YellowBird.h"
#include "BlueBird.h"
#include "Bomb.h"
#include "Egg.h"
#include "BigBird.h"
#include "RedBird.h"
#include "PixelToMeter.h"
#include "EffectFactory.h"
#include "GameObjectMan.h"
#include "BangEvent.h"
#include "TimerMan.h"
#include "AudioManager.h"
#include "ExplosionFeathers.h"

void ContactAction::ContactPair(RedBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 10.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::RED, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
	
}

void ContactAction::ContactPair(RedBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 20.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::RED, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(RedBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::RED, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(RedBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::RED, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);

		AudioManager::Play(Audio::Name::PIG_SING_7);
	}
}

void ContactAction::ContactPair(RedBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::RED, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}


void ContactAction::ContactPair(BigBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 10.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::RED, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}

}

void ContactAction::ContactPair(BigBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 20.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::RED, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(BigBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::RED, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(BigBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::RED, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);

		AudioManager::Play(Audio::Name::PIG_SING_7);
	}
}

void ContactAction::ContactPair(BigBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::RED, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(YellowBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
			if (bird.punchMode && (vel.LengthSquared() > 30.0f))
			{
				pContact->SetEnabled(false);
				block.ReduceHealth(10000);

				// Slow the bird down by some factor
				//bird.GetBody()->ApplyLinearImpulse(.5f * bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
			}
			else
			{
				block.ReduceHealth(pImpulse->normalImpulses[i]);
				bird.ReduceHealth(pImpulse->normalImpulses[i]);
			}
			
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::YELLOW, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(YellowBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 20.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::YELLOW, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(YellowBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 8.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::YELLOW, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(YellowBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::YELLOW, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);

		AudioManager::Play(Audio::Name::PIG_SING_7);
	}
}

void ContactAction::ContactPair(YellowBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::YELLOW, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(BlueBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 25.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::BLUE, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(BlueBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 35.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 35.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::BLUE, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(BlueBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
			if (bird.punchMode && (vel.LengthSquared() > 30.0f))
			{
				pContact->SetEnabled(false);
				block.ReduceHealth(10000);

				// Slow the bird down by some factor
				//bird.GetBody()->ApplyLinearImpulse(.5f * bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
			}
			else
			{
				block.ReduceHealth(pImpulse->normalImpulses[i]);
				bird.ReduceHealth(pImpulse->normalImpulses[i]);
			}

		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::BLUE, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(BlueBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::BLUE, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);

		AudioManager::Play(Audio::Name::PIG_SING_7);
	}
}

void ContactAction::ContactPair(BlueBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::BLUE, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(WhiteBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 10.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::WHITE, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}

}

void ContactAction::ContactPair(WhiteBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 20.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::WHITE, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(WhiteBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::WHITE, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(WhiteBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::WHITE, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);

		AudioManager::Play(Audio::Name::PIG_SING_7);
	}
}

void ContactAction::ContactPair(WhiteBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::WHITE, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}


void ContactAction::ContactPair(Bomb& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 10.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::BLACK, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(Bomb& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 20.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::BLACK, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(Bomb& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::BLACK, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(Bomb& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::BLACK, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);

		AudioManager::Play(Audio::Name::PIG_SING_7);
	}
}

void ContactAction::ContactPair(Bomb& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		//b2Vec2 pos = bird.GetBody()->GetPosition();
		//bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::BLACK, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(Egg& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bird.impact = true;
	block;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(Egg& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bird.impact = true;
	block;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(Egg& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bird.impact = true;
	block;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(Egg& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bird.impact = true;
	block;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(Egg& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bird.impact = true;
	block;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(Egg& bird, CollisionObjectBox& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bird.impact = true;
	block;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(MinionPig& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 10.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(MinionPig& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(MinionPig& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 12.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(MinionPig& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 10.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(MinionPig& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(KingPig& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 15.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(KingPig& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(KingPig& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 20.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(KingPig& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(KingPig& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(BlastSensor& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	block.ReduceHealth(1000.0f);
	bird;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(BlastSensor& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	block.ReduceHealth(1000.0f);
	bird;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(BlastSensor& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	block.ReduceHealth(1000.0f);
	bird;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(BlastSensor& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	block.ReduceHealth(1000.0f);
	bird;
	pContact;
	pImpulse;
}

void ContactAction::ContactPair(BlastSensor& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	block.ReduceHealth(1000.0f);
	bird;
	pContact;
	pImpulse;
}

void ContactAction::ShowBang(b2Contact* pContact)
{
	//normal manifold contains all info...
	int numPoints = pContact->GetManifold()->pointCount;

	//...world manifold is helpful for getting locations
	b2WorldManifold worldManifold;
	pContact->GetWorldManifold(&worldManifold);

	//DebugMsg::out("Drawing %i Bangs\n", numPoints);

	//draw collision points
	for (int i = 0; i < numPoints; i++)
	{
		Rect rect = Rect(MeterToPixel(worldManifold.points[i].x), MeterToPixel(worldManifold.points[i].y), 15.0f, 15.0f);

		BangEvent* newEvent = new BangEvent(EffectFactory::CreateEffect(GameObjectName::Name::Bang, rect));
		TimerMan::AddEvent(0.1f, newEvent);
	}
}