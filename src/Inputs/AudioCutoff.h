#ifndef AUDIO_CUTOFF_H
#define AUDIO_CUTOFF_H

#include "InputSystem.h"

class AudioCutOff : InputSystem
{
public:
	AudioCutOff();
	AudioCutOff(const AudioCutOff&) = delete;
	const AudioCutOff& operator = (const AudioCutOff&) = delete;
	virtual ~AudioCutOff();

	virtual void Update() override;
private:

};


#endif AUDIO_CUTOFF_H