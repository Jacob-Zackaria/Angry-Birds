#ifndef FOURTH_LEVEL_H
#define FOURTH_LEVEL_H

#include "Scene.h"

class FourthLevel : public Scene
{
public:
	FourthLevel();
	FourthLevel(const FourthLevel&) = delete;
	const FourthLevel& operator = (const FourthLevel&) = delete;
	virtual ~FourthLevel();

	virtual void AddSceneElements() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;


};

#endif FOURTH_LEVEL_H