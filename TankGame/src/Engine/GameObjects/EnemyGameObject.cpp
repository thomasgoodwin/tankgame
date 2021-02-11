#include "EnemyGameObject.h"
#include "BulletGameObject.h"

EnemyGameObject::EnemyGameObject()
{
	setObjectName("enemy game object");
	getShape().setFillColor(sf::Color::Red);
}
void EnemyGameObject::initialize() 
{
	GameObject::initialize();
}
void EnemyGameObject::shutdown()
{
	GameObject::shutdown();
}
void EnemyGameObject::tick(float dt)
{
	GameObject::tick(dt);
	if (m_health <= 0)
	{
		markObjectForDestruction();
	}
}
void EnemyGameObject::render()
{
	GameObject::render();
}
void EnemyGameObject::physicsCallback(std::shared_ptr<GameObject> otherObject)
{
	BulletGameObject* bullet = dynamic_cast<BulletGameObject*>(&(*otherObject));
	if (bullet)
	{
		m_health -= bullet->getDamage();
	}
}
