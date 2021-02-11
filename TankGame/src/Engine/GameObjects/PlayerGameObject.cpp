#include "../Engine.h"
#include "PlayerGameObject.h"
#include "BulletGameObject.h"
#include "EnemyGameObject.h"
#include "../Messages/InputMessage.h"
#include "../Components/LaserGunComponent.h"
#include "../Components/CharacterControllerComponent.h"
#include "../Components/PlayerUIComponent.h"
#include "../Systems/SFMLSystem.h"
#include "../Systems/GameObjectSystem.h"
#include "../Systems/GameplaySystem.h"
#include "../Math.h"
#include "../Components/PhysicsComponent.h"


PlayerGameObject::PlayerGameObject(std::shared_ptr<MessageManager> messageManager, unsigned int playerID) : MessageNode(&(*messageManager))
{
  setObjectName("player game object");
  m_playerTexture = std::make_shared<sf::Texture>();
  m_playerTexture->setSmooth(true);
  if (playerID == 1)
  {
    if (!m_playerTexture->loadFromFile("../Assets/blueTank.png"))
    {
      std::cerr << "player's texture couldn't be loaded" << std::endl;
    }
  }
  else
  {
    if (!m_playerTexture->loadFromFile("../Assets/yellowTank.png"))
    {
      std::cerr << "player's texture couldn't be loaded" << std::endl;
    }
  }

  getShape().setTexture(&(*m_playerTexture));
  m_playerID = playerID;
}

void PlayerGameObject::initialize()
{
	GameObject::initialize();
  addComponent(std::make_shared<LaserGunComponent>(1.25f));
  addComponent(std::make_shared<CharacterControllerComponent>());
  addComponent(std::make_shared<PlayerUIComponent>());
  addComponent(std::make_shared<PhysicsComponent>(ColliderType::rectangle));

}
void PlayerGameObject::shutdown()
{
	GameObject::shutdown();
}
void PlayerGameObject::tick(float dt)
{
	GameObject::tick(dt);
  if (m_isFiring == true)
  {
    std::vector<std::shared_ptr<LaserGunComponent>> laserGun;
    getComponents(laserGun);
    if (laserGun.size() > 1)
    {
      std::cerr << "two lasers on the player" << std::endl;
      exit(0);
    }
    laserGun[0]->shoot();
 
    m_isFiring = false;
  }
  if (m_health == 0)
  {
    Engine::get().getGameplaySystem().removePlayerFromCurrentGame(m_playerID);
    markObjectForDestruction();
  }
  
}
void PlayerGameObject::render()
{
	GameObject::render();
}
void PlayerGameObject::move(sf::Vector2f dir)
{
  getShape().move(dir);
}

void PlayerGameObject::onNotify(Message message)
{
  
}

void PlayerGameObject::physicsCallback(std::shared_ptr<GameObject> otherObject)
{
  BulletGameObject* bullet = dynamic_cast<BulletGameObject*>(&(*otherObject));
  if ((bullet != nullptr) && (bullet->getObjectThatShotMe() != this))
  {
    m_health -= bullet->getDamage();
  }

  EnemyGameObject* enemy = dynamic_cast<EnemyGameObject*>(&(*otherObject));
  if (enemy)
  {
    m_health -= enemy->getDamage();
    return;
  }
}