#ifndef FIRST_LEVEL_H
#define FIRST_LEVEL_H

#include "Scene.h"

class FirstLevel : public Scene
{
public:
	FirstLevel();
	FirstLevel(const FirstLevel&) = delete;
	const FirstLevel& operator = (const FirstLevel&) = delete;
	virtual ~FirstLevel();

	virtual void AddSceneElements() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;


};

#endif FIRST_LEVEL_H