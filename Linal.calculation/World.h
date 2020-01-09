#pragma once
#include <vector>
#include "GameObject.h"

class World
{
protected:
	std::vector<GameObject> worldObjects;

public:
	World();
	~World();

	void prepareWorld();
};

