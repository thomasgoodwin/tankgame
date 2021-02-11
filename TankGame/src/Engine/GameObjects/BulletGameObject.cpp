#include "BulletGameObject.h"
#include "PlayerGameObject.h"
#include "EnemyGameObject.h"
#include "SFML/Graphics.hpp"
#include "../Components/Component.h"
#include "WallGameObject.h"
#include "../Math.h"


BulletGameObject::BulletGameObject(sf::Vector2f size, float speed, Component* parent)
{
	getShape().setSize(size);
	getShape().setFillColor(sf::Color::Yellow);
	setObjectName("bullet game object");
	m_speed = speed;
	m_objectThatShotMe = parent->getParent();
	if (m_objectThatShotMe == nullptr)
	{
		std::cerr << "bullet's constructor is hella wac" << std::endl;
	}
	m_direction = sf::Vector2f(cos(MATH::toDegrees(parent->getParent()->getShape().getRotation())), sin(MATH::toDegrees(parent->getParent()->getShape().getRotation())));
	getShape().setRotation(parent->getParent()->getShape().getRotation());
	m_lifeTime = m_maxLifeTime;
}
void BulletGameObject::initialize()
{
	GameObject::initialize();
	addComponent(std::make_shared<PhysicsComponent>(ColliderType::rectangle));
}
void BulletGameObject::shutdown()
{
	GameObject::shutdown();
}
void BulletGameObject::tick(float dt)
{
	GameObject::tick(dt);
	fire(dt);
	if(m_lifeTime > 0.0f)
		m_lifeTime -= dt;
	if (m_lifeTime < 0.0f)
		disable();
}
void BulletGameObject::render()
{
	GameObject::render();
}
void BulletGameObject::fire(float dt)
{
  getShape().move(m_direction.x * m_speed * dt, m_direction.y * m_speed * dt);
}

  // cases are separated for potential effects on hit
void BulletGameObject::physicsCallback(std::shared_ptr<GameObject> otherObject)
{
	WallGameObject* wall = dynamic_cast<WallGameObject*>(&(*otherObject));
	if (wall)
	{
		markObjectForDestruction();
		return;
	}
	PlayerGameObject* player = dynamic_cast<PlayerGameObject*>(&(*otherObject));
	if ((player != nullptr) && (player->getPlayerID() != dynamic_cast<PlayerGameObject*>(m_objectThatShotMe)->getPlayerID()))
	{
		markObjectForDestruction();
		return;
	}
	EnemyGameObject* enemy = dynamic_cast<EnemyGameObject*>(&(*otherObject));
	if (enemy)
	{
		markObjectForDestruction();
		return;
	}
}

void BulletGameObject::recycle()
{
	getShape().setRotation(m_objectThatShotMe->getShape().getRotation());
	m_direction = sf::Vector2f(cos(MATH::toDegrees(m_objectThatShotMe->getShape().getRotation())), sin(MATH::toDegrees(m_objectThatShotMe->getShape().getRotation())));
	m_lifeTime = m_maxLifeTime;
	disable(); // toggle disable to enabled
}
