#pragma once
#include "Graphics.h"
#include "Input.h"
#include "Time.h"
#include "Random.h"
#include "World.h"

class Test
{
public:
	Test();
	~Test();

	virtual void Initialize();
	virtual void Run();

	bool IsQuit() { return m_quit; }

protected:
	void UpdateEvents();

protected:
	bool m_quit{ false };

	Graphics* m_graphics{ nullptr };
	Input* m_input{ nullptr };
	Time* m_time{ nullptr };
	World* m_world{ nullptr };
};
