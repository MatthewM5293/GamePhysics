#pragma once
#include "Contact.h"
#include <vector>
#include "../../Engine/Body.h"

namespace Collision
{
	void CreateContacts(std::vector<Body*> bodies, std::vector<Contact>& contacts);

	Contact GenerateContact(class Body* bodyA, class Body* bodyB);

	void SeperateContacts(std::vector<Contact>& contacts);
}