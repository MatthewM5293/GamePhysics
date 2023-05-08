#pragma once
#include <SDL.h>

class Time
{
public:
	Time();

	void Update();
	float TimeDelta() const { return m_deltaTime; }

private:
	uint64_t m_prevTime{ 0 };
	float m_deltaTime{ 0 };
};