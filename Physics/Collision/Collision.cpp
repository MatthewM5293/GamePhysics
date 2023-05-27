#include "Collision.h"
#include "../../Engine/CircleShape.h"
#include "../../Engine/Random.h"

namespace Collision
{
    void CreateContacts(std::vector<Body*> bodies, std::vector<Contact>& contacts)
    {
        for (size_t i = 0; i < bodies.size() - 1; i++)
        {
            for (size_t j = i + 1; j < bodies.size(); j++)
            {
                Body* bodyA = bodies[i];
                Body* bodyB = bodies[j];

                // contact needs at least one dynamic body
                if (bodyA->type != Body::DYNAMIC && bodyB->type != Body::DYNAMIC) continue;

                // check for intersection between bodies
                if (bodyA->Intersects(bodyB))
                {
                    // create contact
                    Contact contact = Collision::GenerateContact(bodyA, bodyB);
                    contacts.push_back(contact);
                }
            }
        }
    }

    Contact GenerateContact(Body* bodyA, Body* bodyB)
    {
        Contact contact;

        contact.bodyA = bodyA;
        contact.bodyB = bodyB;

        glm::vec2 direction = bodyA->position - bodyB->position;
        float distance = glm::length(direction);

        if (distance == 0)
        {
            direction = { randomf(-0.05f, 0.05f), randomf(-0.05f, 0.05f) };
        }   

        float radius = ((CircleShape*)bodyA->shape)->radius + ((CircleShape*)bodyB->shape)->radius;

        contact.depth = radius - distance;

        contact.normal = glm::normalize(direction);
        

        return contact;
    }
    void SeperateContacts(std::vector<Contact>& contacts)
    {
        for (auto& contact : contacts)
        {
            float totalInvMass = contact.bodyA->invMass + contact.bodyB->invMass;
            glm::vec2 seperation = contact.normal * (contact.depth / totalInvMass);

            contact.bodyA->position += seperation * contact.bodyA->invMass;
            contact.bodyB->position -= seperation * contact.bodyB->invMass;
        }
    }
}
