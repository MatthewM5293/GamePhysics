#pragma once

namespace Integrator
{
	/// <summary>
	/// If velocity isn't constant, this becomes inaccurate.
	/// This integration is fast but unstable.
	/// </summary>
	/// <param name="body"></param>
	/// <param name="dt"></param>
	inline void ExplicitEuler(Body& body, float dt) 
	{
		glm::vec2 acceleration = (body.force * body.invMass);

		body.position += body.velocity * dt;
		body.velocity += acceleration * dt;
	}

	/// <summary>
	/// Most commercial game physics engines.  
	/// This integration is as fast as Explicit Euler but more stable.
	/// </summary>
	/// <param name="body"></param>
	/// <param name="dt"></param>
	inline void SemiImplicitEuler(Body& body, float dt) 
	{
		glm::vec2 acceleration = (body.force * body.invMass);

		body.velocity += acceleration * dt;
		body.position += body.velocity * dt;
	}
}