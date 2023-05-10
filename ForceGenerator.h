#pragma once
#include <vector>

class ForceGenerator
{
public:
	ForceGenerator(class PhysicsObject* physicsObject = nullptr) : m_physicsObject{ physicsObject } {}

	virtual void Apply(std::vector<class Body*> bodies) = 0;
	virtual void Draw(class Graphics* graphics);

protected:
	class PhysicsObject* m_physicsObject{ nullptr };
};