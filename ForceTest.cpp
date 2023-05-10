#include "ForceTest.h"
#include "CircleShape.h"

void ForceTest::Initialize()
{
	//calls parent method
	Test::Initialize();
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity{ 0, 0 }; //randomUnitCircle() * randomf(100, 200);
		auto body = new Body(m_input->GetMousePosition(), velocity, randomf(1, 5));
		float size = randomf(1, 8);
		auto po = new PhysicsObject(body, new CircleShape(size * 7, { randomf(1) , randomf(1) , randomf(1) , 1 }));
		po->GetBody()->damping = 1;
		po->GetBody()->gravityScale = 30;

		m_world->AddPhysicsObject(po);
	}
}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Render()
{
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);
}
