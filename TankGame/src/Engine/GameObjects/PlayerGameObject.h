#ifndef PLAYERGAMEOBJECT_H
#define PLAYERGAMEOBJECT_H
#include "GameObject.h"
#include "../Messages/MessageManager.h"

class PlayerGameObject : public GameObject, MessageNode
{
public:
  PlayerGameObject(std::shared_ptr<MessageManager> messageManager, unsigned int playerID);
  virtual void initialize() override;
  virtual void shutdown() override;
  virtual void tick(float dt) override;
  virtual void render() override;
  virtual void physicsCallback(std::shared_ptr<GameObject>) override;
  void onNotify(Message message);
  void move(sf::Vector2f dir);
  bool isFiring() { return m_isFiring; };
  void isFiring(bool isFiring) { m_isFiring = isFiring; };
  unsigned int getPlayerID() { return m_playerID; };
  int getHealth() { return m_health; };
private:
  bool m_isFiring = false;
  int m_health = 10;
  std::shared_ptr<sf::Texture> m_playerTexture;
  unsigned int m_playerID;
};

#endif