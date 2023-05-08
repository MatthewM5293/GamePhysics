#include "World.h"

World::~World()
{
	m_objects.clear();
}

void World::Step(float dt)
{
	for (auto& i : m_objects)
	{
		i->Step(dt);
	}
}

void World::Draw(Graphics* graphics)
{
	for (auto& i : m_objects)
	{
		i->Draw(graphics);
	}
}

void World::AddPhysicsObject(PhysicsObject* po)
{
	m_objects.push_back(po);
}

void World::RemovePhysicsObject(PhysicsObject* po)
{
	m_objects.remove(po);
}
