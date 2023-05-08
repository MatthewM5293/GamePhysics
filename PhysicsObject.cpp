#include "PhysicsObject.h"

PhysicsObject::~PhysicsObject()
{
	delete m_body;
	delete m_shape;
}
void PhysicsObject::Step(float dt)
{
	m_body->Step(dt);
}
void PhysicsObject::Draw(Graphics* graphics)
{
	m_shape->Draw(graphics, m_body->position);
	// <call draw on the shape (pass in the graphics and body position)>
}