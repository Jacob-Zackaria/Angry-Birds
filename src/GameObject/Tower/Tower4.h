#ifndef TOWER_FOUR_H
#define TOWER_FOUR_H

#include "GameObject2D.h"
#include "Tower.h"
class Tower4 : public Tower
{
public:
	Tower4(const float newX, const float newY, const int height);
	Tower4(const Tower4&) = delete;
	const Tower4& operator = (const Tower4&) = delete;
	virtual ~Tower4();

	void Build() override;
	void Destroy() override;
};

#endif TOWER_FOUR_H