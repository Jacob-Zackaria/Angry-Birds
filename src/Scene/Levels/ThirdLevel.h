#ifndef THIRD_LEVEL_H
#define THIRD_LEVEL_H

#include "Scene.h"

class ThirdLevel : public Scene
{
public:
	ThirdLevel();
	ThirdLevel(const ThirdLevel&) = delete;
	const ThirdLevel& operator = (const ThirdLevel&) = delete;
	virtual ~ThirdLevel();

	virtual void AddSceneElements() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

};

#endif THIRD_LEVEL_H