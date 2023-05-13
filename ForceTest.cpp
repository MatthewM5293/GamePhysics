#include "ForceTest.h"
#include "Body.h"
#include "CircleShape.h"
#include "GravitationalGenerator.h"

void ForceTest::Initialize()
{
	//calls parent method
	Test::Initialize();

	auto forceGenerator = new GravitationalGenerator(400);
	m_world->AddForceGenerator(forceGenerator);
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(100, 200);
		float size = randomf(1, 8);
		auto body = new Body(new CircleShape(size * 7, { randomf(1) , randomf(1) , randomf(1) , 1 }), m_input->GetMousePosition(), velocity, randomf(1, 5));
		body->damping = 1;
		body->gravityScale = 30;

		m_world->AddBody(body);
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
