#ifndef GAMEOBJECTSYSTEM_H
#define GAMEOBJECTSYSTEM_H

#include "System.h"
#include "../Messages/MessageManager.h"
#include "PhysicsSystem.h"
#include <vector>
#include <memory>

#define A_GOOD_START 100

class GameObject;

class GameObjectSystem : public System, MessageNode
{
public:
  GameObjectSystem(std::shared_ptr<MessageManager> messageManager) : MessageNode(&(*messageManager)) { m_gameObjects.reserve(A_GOOD_START); };
  virtual void initialize() override;
  virtual void tick(float dt) override;
  virtual void render() override;
  virtual void shutdown() override;
  void addGameObject(const std::shared_ptr<GameObject>& gameObject);

  virtual const std::string getSystemName() const override { return "game object system"; };
  std::vector<std::shared_ptr<GameObject>>& getGameObjects() { return m_gameObjects; };

  template <typename tGameObject>
  std::vector<std::shared_ptr<tGameObject>> getGameObjectsOfType() const
  {
    std::vector<std::shared_ptr<tGameObject>> gameObjects;
    for (const auto& go : m_gameObjects)
    {
      std::shared_ptr<tGameObject> goCast = std::dynamic_pointer_cast<tGameObject>(go);
      if (goCast)
      {
        gameObjects.push_back(goCast);
      }
    }
    return gameObjects;
  }
  void clearObjects();

private:
  std::vector<std::shared_ptr<GameObject>> m_gameObjects;

};
#endif