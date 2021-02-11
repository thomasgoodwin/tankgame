#include "TankGame.h"
#include "../Engine.h"
#include "SFML/Graphics.hpp"
#include "../GameObjects/PlayerGameObject.h"
#include "../GameObjects/MapGameObject.h"
#include "../Systems/SFMLSystem.h"
#include "../Systems/GameObjectSystem.h"

void TankGame::initialize()
{
  auto messageManager = Engine::get().getSharedMessageManager();
  sf::Vector2u windowSize = Engine::get().getSFMLSystem().getWindow()->getSize();

  // create player 1
  unsigned int player1ID = 1;
  auto player1 = std::make_shared<PlayerGameObject>(messageManager, player1ID);
  player1->setSize(sf::Vector2f(100, 100));
  player1->setPos(sf::Vector2f(windowSize.x / 6, windowSize.y / 1.1));
  player1->getShape().setOrigin(sf::Vector2f(player1->getSize().x / 2, player1->getSize().y / 2));
  Engine::get().getGameObjectSystem().addGameObject(player1);
  addPlayer(player1ID);

  // create player 2
  unsigned int player2ID = 2;
  auto player2 = std::make_shared<PlayerGameObject>(messageManager, player2ID);
  player2->setSize(sf::Vector2f(100, 100));
  player2->setPos(sf::Vector2f(windowSize.x / 1.1f, windowSize.y / 6));
  player2->getShape().setOrigin(sf::Vector2f(player2->getSize().x / 2, player2->getSize().y / 2));
  Engine::get().getGameObjectSystem().addGameObject(player2);
  addPlayer(player2ID);

  //create map
  auto map = std::make_shared<MapGameObject>();
  Engine::get().getGameObjectSystem().addGameObject(map);


}
void TankGame::begin()
{

}
void TankGame::tick(float dt)
{

}
void TankGame::render()
{

}
void TankGame::end()
{

}
void TankGame::shutdown()
{

}
