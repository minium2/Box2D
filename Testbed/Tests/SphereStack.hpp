/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef SPHERE_STACK_HPP
#define SPHERE_STACK_HPP

class SphereStack : public Test
{
public:

	enum
	{
		e_count = 10
	};

	SphereStack()
	{
		{
			b2::BodyDef bd;
			b2::Body* ground = m_world->CreateBody(&bd);

			b2::EdgeShape shape;
			shape.Set(b2::Vec2(-40.0f, 0.0f), b2::Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2::CircleShape shape;
			shape.m_radius = 1.0f;

			for (b2::int32 i = 0; i < e_count; ++i)
			{
				b2::BodyDef bd;
				bd.type = b2::dynamicBody;
				bd.position.Set(0.0, 4.0f + 3.0f * i);

				m_bodies[i] = m_world->CreateBody(&bd);

				m_bodies[i]->CreateFixture(&shape, 1.0f);

				m_bodies[i]->SetLinearVelocity(b2::Vec2(0.0f, -50.0f));
			}
		}
	}

	void Step(Settings* settings)
	{
		Test::Step(settings);

		//for (b2::int32 i = 0; i < e_count; ++i)
		//{
		//	std::printf("%g ", m_bodies[i]->GetWorldCenter().y);
		//}

		//for (b2::int32 i = 0; i < e_count; ++i)
		//{
		//	std::printf("%g ", m_bodies[i]->GetLinearVelocity().y);
		//}

		//printf("\n");
	}

	static Test* Create()
	{
		return new SphereStack;
	}

	b2::Body* m_bodies[e_count];
};

#endif
