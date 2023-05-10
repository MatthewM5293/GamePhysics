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
public:
	static glm::vec2 gravity;

private:
	std::list<PhysicsObject*> m_objects;
};
