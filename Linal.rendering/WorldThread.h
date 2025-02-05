#pragma once
#include "View.h"
#include "../Linal.calculation/World.h"
#include "Renderer.h"
#include "../Linal.calculation/Mesh.h"

public ref class WorldThread
{
protected:
	View^ mainView;
	World* world;
	Renderer* renderer;

	void checkCollisions();
	void lose();
	void win();

public:
	WorldThread() {};
	WorldThread(View^ mainView);
	~WorldThread();

	void run();

	/// <summary> updates all world objects </summary>
	void updateWorld(System::TimeSpan deltaTime);

	/// <summary> handles all window inputs, can edit world objects </summary>
	void handleInputs(System::Char input);
};

