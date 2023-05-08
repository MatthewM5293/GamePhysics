#include "Body.h"

void Body::Step(float dt)
{
	position += velocity * dt;
}
