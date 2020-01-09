#pragma once
#include "View.h"
#include "../Linal.calculation/World.h"

public ref class WorldThread
{
protected:
	View^ mainView;
	World* world;

	/// <summary> converts the mesh of an object to a list of RenderLine objects, it does this using the triangles variable </summary>
	System::Collections::Generic::List<RenderLine>^ meshToLines();
public:
	WorldThread() {};
	WorldThread(View^ mainView);
	~WorldThread();

	void run();

	/// <summary> updates all world objects </summary
	void updateWorld(System::TimeSpan deltaTime);

	/// <summary> handles all window inputs, can edit world objects </summary>
	void handleInputs(System::Char input);
};

