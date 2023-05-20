#include "JointTest.h"
#include "CircleShape.h"
#include "World.h"
#include "Body.h"
#include "Joint.h"

//#define CHAIN

#define SPRING_STIFFNESS	200
#define SPRING_LENGTH		100
#define BODY_DAMPING		50
#define CHAIN_SIZE			4
#define GRID_SIZE			5

void JointTest::Initialize()
{
	Test::Initialize();
	//for loop
	m_anchor = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 100 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBody(m_anchor);
	auto prevBody = m_anchor;

#if defined(CHAIN)
	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		auto body = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 + (i * 100) }, { 0, 0 }, 1, Body::DYNAMIC);
		body->gravityScale = 250;
		body->damping = BODY_DAMPING;
		m_world->AddBody(body);

		auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody = body;
	}
#else
	auto prevBodyA = m_anchor;
	auto prevBodyB = m_anchor;

	for (int i = 0; i < GRID_SIZE; i++)
	{
		auto bodyA = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 + (i * 100) }, { 0, 0 }, 1, Body::DYNAMIC);
		bodyA->gravityScale = 250;
		bodyA->damping = BODY_DAMPING;
		m_world->AddBody(bodyA);

		auto bodyB = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 800, 200 + (i * 100) }, { 0, 0 }, 1, Body::DYNAMIC);
		bodyB->gravityScale = 250;
		bodyB->damping = BODY_DAMPING;
		m_world->AddBody(bodyB);

		if (i == 0)
		{
			auto joint = new Joint(m_anchor, bodyA, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			//anchorB
			auto joint2 = new Joint(m_anchor, bodyB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint2);
		}
		else
		{
			//Verticles
			auto joint = new Joint(prevBodyA, bodyA, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);
			
			auto joint2 = new Joint(prevBodyB, bodyB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint2);
			
			//Diagonals
			auto joint3 = new Joint(prevBodyB, bodyA, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint3);
			
			auto joint4 = new Joint(prevBodyA, bodyB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint4);
		}

		//neighbor
		auto joint5 = new Joint(bodyB, bodyA, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint5);


		prevBodyA = bodyA;
		prevBodyB = bodyB;
	}
#endif


}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_input->GetMousePosition();
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);
}