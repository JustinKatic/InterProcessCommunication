#pragma once
#include <vector>
#include"fixWindows.h"
#include<windows.h>


struct Entity 
{
	float x = 0, y = 0;
	float rotation = 0;
	float speed = 0;
	unsigned char r = 0, g = 0, b = 0;
	float size = 1;
};

class EntityEditorApp 
{
public:
	EntityEditorApp(int screenWidth = 800, int screenHeight = 450);
	~EntityEditorApp();

	bool Startup();
	void Shutdown();

	void Update(float deltaTime);
	void Draw();


	bool WriteToSharedMemory();



protected:
	//creates a handle mem variable
	HANDLE m_filehandleData;
	HANDLE m_filehandleSize;

	int m_screenWidth;
	int m_screenHeight;

	// define a block of entities that should be shared
	enum { ENTITY_COUNT = 50 };
	Entity m_entities[ENTITY_COUNT];
};