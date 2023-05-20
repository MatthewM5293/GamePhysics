#include "Body.h"
#include "Integrator.h"
#include "World.h"
#include "Shape.h"
#include "CircleShape.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{
	if (type != DYNAMIC) return;

	//gravity
	ApplyForce(World::gravity * gravityScale * mass);

	Integrator::ExplicitEuler(*this, dt);
	ClearForce();

	velocity *= (1.0f / (1.0f + (damping * dt)));
}

void Body::Draw(Graphics* m_graphics)
{
	shape->Draw(m_graphics, position);
}

bool Body::Intersects(Body* body)
{
	glm::vec2 direction = body->position - position;
	float distance = glm::length(direction);
	float radius = dynamic_cast<CircleShape*>(shape)->radius - dynamic_cast<CircleShape*>(body->shape)->radius;
	
	return distance <= radius;
}