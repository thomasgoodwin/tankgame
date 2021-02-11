#include "Engine.h"
#include "Systems/SFMLSystem.h"
#include "Systems/GameObjectSystem.h"
#include "Messages/MessageManager.h"
#include "Systems/GameplaySystem.h"
#include "Systems/PhysicsSystem.h"

Engine::Engine() : m_messageManager(std::make_shared<MessageManager>()),
                   m_allSystems({ std::make_unique<SFMLSystem>(m_messageManager),
                                  std::make_unique<GameObjectSystem>(m_messageManager),
                                  std::make_unique<GameplaySystem>(m_messageManager),
                                  std::make_unique<PhysicsSystem>(m_messageManager) })
{

}

void Engine::initialize()
{
  for (auto& system : m_allSystems)
  {
    system->initialize();
  }
}

Engine::~Engine()
{
  getSFMLSystem().getWindow()->close();
}

void Engine::gameLoop()
{
  m_currentTime = std::chrono::system_clock::now();
  while (m_gameIsRunning)
  {
    auto newCurrentTime = std::chrono::system_clock::now();
    std::chrono::duration<float> elapsedTime = (newCurrentTime - m_currentTime);
    m_currentTime = newCurrentTime;
    float dt = elapsedTime.count();
    //std::cout << dt << std::endl;
    m_messageManager->notify();
    tick(dt);
    render();
  }
}

void Engine::shutdown()
{
  for (auto itr = m_allSystems.rbegin(); itr != m_allSystems.rend(); ++itr)
  {
    (*itr)->shutdown();
  }
}

void Engine::stopGame()
{
  m_gameIsRunning = false;
}

void Engine::tick(float dt)
{
  for (auto& system : m_allSystems)
  {
    system->tick(dt);
  }
}

void Engine::render()
{
  for (auto& system : m_allSystems)
  {
    system->render();
  }
}

SFMLSystem& Engine::getSFMLSystem()
{
  return *reinterpret_cast<SFMLSystem*>(Engine::get().m_allSystems[0].get());
}

GameObjectSystem& Engine::getGameObjectSystem()
{
  return *reinterpret_cast<GameObjectSystem*>(Engine::get().m_allSystems[1].get());
}

GameplaySystem& Engine::getGameplaySystem()
{
  return *reinterpret_cast<GameplaySystem*>(Engine::get().m_allSystems[2].get());
}
PhysicsSystem& Engine::getPhysicsSystem()
{
  return *reinterpret_cast<PhysicsSystem*>(Engine::get().m_allSystems[3].get());
}

MessageManager& Engine::getMessageManager()
{
  return *(Engine::get().m_messageManager);
}

std::shared_ptr<MessageManager> Engine::getSharedMessageManager()
{
  return std::shared_ptr<MessageManager>(Engine::get().m_messageManager);
}