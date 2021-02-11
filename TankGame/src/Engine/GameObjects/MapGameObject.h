#ifndef MAPGAMEOBJECT_H
#define MAPGAMEOBJECT_H
#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <memory>

class MapGameObject : public GameObject
{
public:
  MapGameObject();
  virtual void initialize() override;
  virtual void shutdown() override;
  virtual void tick(float dt) override;
  virtual void render() override;
  virtual void physicsCallback(std::shared_ptr<GameObject>) override;
private:
  std::vector<std::shared_ptr<sf::Shape>> m_mapShapes;
};

#endif