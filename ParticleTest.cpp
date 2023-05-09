#include "ParticleTest.h"
#include "CircleShape.h"

void ParticleTest::Initialize()
{
	//calls parent method
	Test::Initialize();
}

void ParticleTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(100, 200);
		auto po = new PhysicsObject(new Body(m_input->GetMousePosition(), velocity), new CircleShape(randomf(10, 50), { randomf(1) , randomf(1) , randomf(1) , 1 }));
		m_world->AddPhysicsObject(po);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ParticleTest::Render()
{
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);
}
