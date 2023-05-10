#include "ForceGenerator.h"
#include "PhysicsObject.h"

void ForceGenerator::Draw(Graphics* graphics)
{
	if (m_physicsObject) m_physicsObject->Draw(graphics);
}
