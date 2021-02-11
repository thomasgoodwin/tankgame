#include "GameplaySystem.h"
#include "GameObjectSystem.h"
#include "../GameObjects/PlayerGameObject.h"
#include "../GameObjects/EnemyGameObject.h"
#include "../GameObjects/MapGameObject.h"
#include "../Systems/SFMLSystem.h"
#include "../Engine.h"
#include "SFML/Graphics.hpp"
#include "../Games/TankGame.h"

void GameplaySystem::initialize()
{
  m_games.push_back(std::make_shared<TankGame>());
  
  for (auto& game : m_games)
  {
    game->initialize();
  }
  setNextGame(Tanks);
}
 void GameplaySystem::tick(float dt)
{
   m_games[m_currentGame]->tick(dt);
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
   {
     if (m_currentGame == Tanks)
     {
       m_games[m_currentGame]->end();
       m_games[m_currentGame]->begin();
     }
   }
}
void GameplaySystem::render()
{
  m_games[m_currentGame]->render();
}
void GameplaySystem::shutdown()
{
  for (auto& game : m_games)
  {
    game->shutdown();
  }
}
void GameplaySystem::setNextGame(int newGame)
{
  if (m_games[m_currentGame]->isRunning())
  {
    m_games[m_currentGame]->end();
    Engine::get().getGameObjectSystem().clearObjects();
  }
  m_games[m_currentGame]->isRunning(false);
  m_currentGame = newGame;

  m_games[m_currentGame]->begin();
  m_games[m_currentGame]->isRunning(true);
}