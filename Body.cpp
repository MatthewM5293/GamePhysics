#include "Body.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{
	glm::vec2 acceleration = (force * invMass);

	velocity += acceleration * dt;
	position += velocity * dt;

	velocity *= (1.0f / (1.0f + (dt * 2.0f))); //damping = 2
}
