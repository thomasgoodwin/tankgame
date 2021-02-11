#include "WallGameObject.h"
#include "BulletGameObject.h"

WallGameObject::WallGameObject(int health)
{
	setObjectName("wall game object");
	getShape().setFillColor(sf::Color::Red);
	m_health = health;
}
void WallGameObject::initialize()
{
	GameObject::initialize();
}
void WallGameObject::shutdown()
{
	GameObject::shutdown();
}
void WallGameObject::tick(float dt)
{
	GameObject::tick(dt);
	if (m_health == 0)
	{
		markObjectForDestruction();
	}
}
void WallGameObject::render()
{
	GameObject::render();
}
void WallGameObject::physicsCallback(std::shared_ptr<GameObject> otherObject)
{
	BulletGameObject* bullet = dynamic_cast<BulletGameObject*>(&(*otherObject));
	if (bullet && m_health > 0) // if this wall is indestructable its health is -1
	{
		m_health -= bullet->getDamage();
	}
}
