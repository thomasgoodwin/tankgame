#include "PhysicsSystem.h"
#include "../Engine.h"
#include "GameObjectSystem.h"
#include "../GameObjects/GameObject.h"
#include "../Math.h"
#include "../Components/PhysicsComponent.h"

void PhysicsSystem::initialize()
{

}

void PhysicsSystem::tick(float dt)
{
	auto& allGameObjects = Engine::get().getGameObjectSystem().getGameObjects();

	for (int i = 0; i < allGameObjects.size(); i++)
	{
		for (int j = i + 1; j < allGameObjects.size(); j++)
		{
			auto& object1 = allGameObjects[i];
			auto& object2 = allGameObjects[j];

			auto object1PhysComponent = object1->getComponentOfType<PhysicsComponent>();
			auto object2PhysComponent = object2->getComponentOfType<PhysicsComponent>();
			if (object1PhysComponent == nullptr ||
				object2PhysComponent == nullptr)
			{
				continue;
			}
			  // circle circle case
			if (object1PhysComponent->getColliderType() == ColliderType::circle &&
				object2PhysComponent->getColliderType() == ColliderType::circle)
			{
				  // janky circle circle collision detection
				float object1AVG = (object1->getSize().x + object1->getSize().y) / 2.9;
				float object2AVG = (object2->getSize().x + object2->getSize().y) / 2.9;

				if (MATH::distance(object1->getPosition(), object2->getPosition()) < object1AVG + object2AVG)
				{ // collision resolution
					object1->physicsCallback(object2);
					object2->physicsCallback(object1);
				}
			}
			  // rectangle rectangle case
			else if (object1PhysComponent->getColliderType() == ColliderType::rectangle &&
							object2PhysComponent->getColliderType() == ColliderType::rectangle)
			{
				if (object1->getPosition().x < object2->getPosition().x + object2->getSize().x &&
					object1->getPosition().x + object1->getSize().x > object2->getPosition().x &&
					object1->getPosition().y < object2->getPosition().y + object1->getSize().y &&
					object1->getPosition().y + object1->getSize().y > object2->getPosition().y)
				{
					object1->physicsCallback(object2);
					object2->physicsCallback(object1);
				}
			}
			else // circle rectangle case
			{
				if (object1PhysComponent->getColliderType() == ColliderType::circle) 
				{
					if (circleRect(object1->getPosition().x, object1->getPosition().y, object1->getSize().x, 
						object2->getPosition().x, object2->getPosition().y, object2->getSize().x, object2->getSize().y))
					{
						object1->physicsCallback(object2);
						object2->physicsCallback(object1);
					}
				}
				else // object 2 is circle
				{
					if (circleRect(object2->getPosition().x, object2->getPosition().y, object2->getSize().x, 
							object1->getPosition().x, object1->getPosition().y, object1->getSize().x, object1->getSize().y))
					{
						object1->physicsCallback(object2);
						object2->physicsCallback(object1);
					}
				}
			}
		}
	}
}

void PhysicsSystem::render()
{

}

void PhysicsSystem::shutdown()
{

}

bool PhysicsSystem::circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh) 
{
	// temporary variables to set edges for testing
	float testX = cx;
	float testY = cy;

	// which edge is closest?
	if (cx < rx)         testX = rx;      // test left edge
	else if (cx > rx + rw) testX = rx + rw;   // right edge
	if (cy < ry)         testY = ry;      // top edge
	else if (cy > ry + rh) testY = ry + rh;   // bottom edge

	// get distance from closest edges
	float distX = cx - testX;
	float distY = cy - testY;
	float distance = sqrt((distX * distX) + (distY * distY));

	// if the distance is less than the radius, collision!
	if (distance <= radius) {
		return true;
	}
	return false;
}


/* code graveyard
// AABB
	(object1->getRight() > object2->getPosition().x &&
	(object1->getTop() < object2->getPosition().y + object2->getSize().y) &&
	(object1->getBottom() > object2->getPosition().y))
//
*/