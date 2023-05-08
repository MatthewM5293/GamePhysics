#pragma once
#include "PhysicsObject.h"
#include <list>

class World
{
public:
	~World();
	void Step(float dt);
	void Draw(class Graphics* graphics);
	void AddPhysicsObject(PhysicsObject* po);
	void RemovePhysicsObject(PhysicsObject* po);
private:
	std::list<PhysicsObject*> m_objects;
};
