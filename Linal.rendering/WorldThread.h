#pragma once
#include "View.h"
#include "../Linal.calculation/World.h"

public ref class WorldThread
{
protected:
	View^ mainView;
	World* world;

public:
	WorldThread() {};
	WorldThread(View^ mainView);
	~WorldThread();

	void run();
	void handleInputs(System::Char input);
};

