#include "Body.h"
#include "Integrator.h"
#include "World.h"

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

	velocity *= (1.0f / (1.0f + (damping * dt))); //damping = 2
}
