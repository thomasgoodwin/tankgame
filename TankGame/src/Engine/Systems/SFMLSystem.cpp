#include "SFMLSystem.h"
#include "../Messages/InputMessage.h"
#include "GameObjectSystem.h"
#include "../Engine.h"
#include "../GameObjects/GameObject.h"
#include <iostream>

void SFMLSystem::initialize()
{
  m_centerWindow = std::make_shared< sf::Vector2i>((sf::VideoMode::getDesktopMode().width / 2) , 
                                                   (sf::VideoMode::getDesktopMode().height / 2));
  m_window = std::make_shared<sf::RenderWindow>();
  m_event = std::make_shared<sf::Event>();

  m_window->create(sf::VideoMode(800, 800), "Projectile File", sf::Style::Default);
  m_window->setPosition(*m_centerWindow);
  m_window->setKeyRepeatEnabled(true);

  m_font = std::make_shared<sf::Font>();
  if (!m_font->loadFromFile("../Assets/arial.ttf"))
  {
    std::cerr << "error loading font" << std::endl;
  }
}

void SFMLSystem::tick(float dt)
{
  while (m_window->pollEvent(*m_event))
  {
    switch (m_event->type)
    {

    case sf::Event::Closed:
      Engine::get().stopGame();
    }
  }
}

void SFMLSystem::render()
{
  m_window->clear();
  auto& gameObjects = Engine::get().getGameObjectSystem().getGameObjects();
  for (int i = 0; i < gameObjects.size(); i++)
  {
    if (gameObjects[i]->isDisabled())
    {
       continue;
    }
    if (gameObjects[i]->isObjectMarkedForDestruction())
    {
      gameObjects.erase(gameObjects.begin() + i);
      continue;
    }
    gameObjects[i]->render();
  }
  m_window->display();
}

void SFMLSystem::shutdown()
{

}

std::shared_ptr<sf::RenderWindow> SFMLSystem::getWindow()
{
  return m_window;
}
