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

	velocity *= (1.0f / (1.0f + (damping * dt))); //damping = 2
}

void Body::Draw(Graphics* m_graphics)
{
	shape->Draw(m_graphics, position);
}

bool Body::Intersects(Body* body)
{
	glm::vec2 direction = this->position - body->position;//<get direction vector of the two bodies>
	float distance = glm::length(direction);//<get length of direction vector>
	float radius = ((CircleShape*)(shape))->radius - ((CircleShape*)(body->shape))->radius;//new CircleShape(shape->size, shape->color) - new CircleShape(body->shape->size, body->shape->color); //<get the radius of this shape and the other shape and add them>
	return distance <= radius;
}