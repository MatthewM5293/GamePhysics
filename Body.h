#pragma once
#include "glm/glm.hpp"

class Body
{
public:
	Body(const glm::vec2& position, const glm::vec2& velocity) : 
		position{ position }, 
		velocity{ velocity }
	{}

	Body(const glm::vec2& position, const glm::vec2& velocity, float mass) : 
		position{ position }, 
		velocity{ velocity },
		mass{ mass }
	{
		invMass = ( mass == 0) ? 0 : 1 / mass;
	}


	void ApplyForce(const glm::vec2& force);
	void Step(float dt);
	void ClearForce() { force = glm::vec2{ 0, 0 }; }

public:
	glm::vec2 position{ 0, 0 };
	glm::vec2 velocity{ 0, 0 };
	glm::vec2 force{ 0, 0 }; //m * a // a = F / m


	float mass{ 1 };
	float invMass{ 1 };
};