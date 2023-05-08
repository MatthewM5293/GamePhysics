#pragma once
#include "glm/glm.hpp"

class Body
{
public:
	Body(const glm::vec2& position, const glm::vec2& velocity) : 
		position{ position }, 
		velocity{ velocity }
	{}

	void Step(float dt);

public:
	glm::vec2 position{ 0, 0 };
	glm::vec2 velocity{ 0, 0 };
};