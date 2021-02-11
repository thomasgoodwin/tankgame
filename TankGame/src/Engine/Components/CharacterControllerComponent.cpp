#include "CharacterControllerComponent.h"
#include "../Math.h"
#include "../GameObjects/PlayerGameObject.h"
#include "../Engine.h"
#include "../Systems/SFMLSystem.h"

CharacterControllerComponent::CharacterControllerComponent()
{
}

CharacterControllerComponent::~CharacterControllerComponent()
{

}

void CharacterControllerComponent::initialize()
{
  PlayerGameObject* player = dynamic_cast<PlayerGameObject*>(getParent());
  MATH::calculateDirectionVector(m_directionVector, player->getShape().getRotation());
}

void CharacterControllerComponent::shutdown()
{

}


void CharacterControllerComponent::tick(float dt)
{
  PlayerGameObject* player = dynamic_cast<PlayerGameObject*>(getParent());
  if (player->getPlayerID() == 1)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
      MATH::calculateDirectionVector(m_directionVector, player->getShape().getRotation());
      sf::Vector2f movementDelta = sf::Vector2f(m_directionVector.x * m_moveSpeed * dt, m_directionVector.y * m_moveSpeed * dt);
      if (!checkBounds(movementDelta))
      {
        player->move(movementDelta);
      }
      //std::cout << player->getPosition().x << ", " << player->getPosition().y << std::endl;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
      MATH::calculateDirectionVector(m_directionVector, player->getShape().getRotation());
      sf::Vector2f movementDelta = sf::Vector2f(m_directionVector.x * -m_moveSpeed * dt, m_directionVector.y * -m_moveSpeed * dt);
      if (!checkBounds(movementDelta))
      {
        player->move(movementDelta);
      }
      //std::cout << player->getPosition().x << ", " << player->getPosition().y << std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
      player->isFiring(true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      player->getShape().setRotation(player->getShape().getRotation() - (dt * m_rotationSpeed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
      player->getShape().setRotation(player->getShape().getRotation() + (dt * m_rotationSpeed));
    }
  }
  else
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
      MATH::calculateDirectionVector(m_directionVector, player->getShape().getRotation());
      sf::Vector2f movementDelta = sf::Vector2f(m_directionVector.x * m_moveSpeed * dt, m_directionVector.y * m_moveSpeed * dt);
      if (!checkBounds(movementDelta))
      {
        player->move(movementDelta);
      }
      //std::cout << player->getPosition().x << ", " << player->getPosition().y << std::endl;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
      MATH::calculateDirectionVector(m_directionVector, player->getShape().getRotation());
      sf::Vector2f movementDelta = sf::Vector2f(m_directionVector.x * -m_moveSpeed * dt, m_directionVector.y * -m_moveSpeed * dt);
      if (!checkBounds(movementDelta))
      {
        player->move(movementDelta);
      }
      //std::cout << player->getPosition().x << ", " << player->getPosition().y << std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
      player->isFiring(true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    {
      player->getShape().setRotation(player->getShape().getRotation() - (dt * m_rotationSpeed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
      player->getShape().setRotation(player->getShape().getRotation() + (dt * m_rotationSpeed));
    }
  }
}
void CharacterControllerComponent::render()
{

}

bool CharacterControllerComponent::checkBounds(sf::Vector2f movementDelta)
{
  PlayerGameObject* player = dynamic_cast<PlayerGameObject*>(getParent());
  sf::Vector2u windowSize = Engine::get().getSFMLSystem().getWindow()->getSize();
  sf::Vector2f playerNewPosition = { player->getPosition().x + movementDelta.x , player->getPosition().y + movementDelta.y  };
  if (playerNewPosition.x < 0.0f || playerNewPosition.y < 0.0f || playerNewPosition.x > windowSize.x || playerNewPosition.y > windowSize.y)
  {
    return true;
  }
  return false;
}