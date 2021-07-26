#include "AudioCutOff.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Keyboard.h"
AudioCutOff::~AudioCutOff()
{
}

void AudioCutOff::Update()
{
	static bool pressed = false;
	static bool once = true;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_M) && !pressed)
	{
		if (once)
		{
			once = false;
			AudioManager::Stop(Audio::Name::BACKGROUND);
		}
		else
		{
			once = true;
			AudioManager::Play(Audio::Name::BACKGROUND);
		}
		
	}
	pressed = Keyboard::GetKeyState(AZUL_KEY::KEY_M);
}


AudioCutOff::AudioCutOff()
{
}
