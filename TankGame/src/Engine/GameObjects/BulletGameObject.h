#ifndef BULLETGAMEOBJECT_H
#define BULLETGAMEOBJECT_H
#include "GameObject.h"

class Component;

class BulletGameObject : public GameObject
{
public:
  BulletGameObject(sf::Vector2f size, float speed, Component* parent);
  virtual void initialize() override;
  virtual void shutdown() override;
  virtual void tick(float dt) override;
  virtual void render() override;
  void fire(float dt);
  int getDamage() { return m_damage; };
  void physicsCallback(std::shared_ptr<GameObject>);
  void recycle();
  GameObject* getObjectThatShotMe() { return m_objectThatShotMe; };
private:
  sf::Vector2f m_direction;
  float m_speed = 3000.0f;
  int m_damage = 1;
  float m_lifeTime = 0;
  float m_maxLifeTime = 2.0f;
  GameObject* m_objectThatShotMe = nullptr;
};
#endif 
