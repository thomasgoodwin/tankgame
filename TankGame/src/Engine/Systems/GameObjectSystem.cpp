#include "../GameObjects/GameObject.h";
#include "GameObjectSystem.h"

void GameObjectSystem::initialize()
{
}

void GameObjectSystem::tick(float dt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (m_gameObjects[i]->isDisabled())
		{
			continue;
		}
		if (m_gameObjects[i]->isObjectMarkedForDestruction())
		{
			m_gameObjects[i]->shutdown();
			m_gameObjects.erase(m_gameObjects.begin() + i);
			continue;
		}
		m_gameObjects[i]->tick(dt);
	}
}

void GameObjectSystem::render()
{

}

void GameObjectSystem::shutdown()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->shutdown();
	}
}

void GameObjectSystem::addGameObject(const std::shared_ptr<GameObject>& gameObject)
{
	m_gameObjects.push_back(gameObject);
	gameObject->initialize();
}

void GameObjectSystem::clearObjects()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->shutdown();
	}
	m_gameObjects.clear();
}