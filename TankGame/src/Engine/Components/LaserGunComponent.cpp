#include "LaserGunComponent.h"
#include <memory>
#include "../GameObjects/BulletGameObject.h"
#include "../GameObjects/PlayerGameObject.h"
#include "../Engine.h"
#include "../Systems/GameObjectSystem.h"

LaserGunComponent::LaserGunComponent(float cooldown)
{
	m_maxCooldown = cooldown;
	m_currentCooldown = m_maxCooldown;
}
LaserGunComponent::~LaserGunComponent()
{

}
void LaserGunComponent::initialize()
{

}
void LaserGunComponent::shutdown() 
{

}
void LaserGunComponent::tick(float dt)
{
	if (m_currentCooldown > 0.0f)
	{
		m_currentCooldown -= dt;
	}
	if (m_currentCooldown < 0.0f)
	{
		m_canShoot = true;
		m_currentCooldown = 0;
	}
}
void LaserGunComponent::render()
{

}

void LaserGunComponent::shoot()
{
	if (!m_canShoot)
		return;
	if (m_bullets.size() < m_bulletCacheLimit)
	{
		auto newBullet = std::make_shared<BulletGameObject>(sf::Vector2f(50, 5), 3000.0f, this);
		auto parentShape = getParent()->getShape();
		newBullet->setPos(sf::Vector2f(parentShape.getPosition().x + parentShape.getScale().x / 4, parentShape.getPosition().y + parentShape.getScale().y / 4)); // todo: offset dont work
		Engine::get().getGameObjectSystem().addGameObject(newBullet);
		m_bullets.push_back(newBullet);
	}
	else
	{
		for (int i = 0; i < m_bullets.size(); i++)
		{
			if (m_bullets[i]->isDisabled())
			{
 				m_bullets[i]->recycle();
				auto parentShape = getParent()->getShape();
				m_bullets[i]->setPos(sf::Vector2f(parentShape.getPosition().x - parentShape.getScale().x , parentShape.getPosition().y + parentShape.getScale().y / 4)); // todo: offset dont work
				break;
			}
		}
	}
	m_currentCooldown += m_maxCooldown;
	m_canShoot = false;
}
