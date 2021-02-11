#ifndef ENEMYGAMEOBJECT_H
#define ENEMYGAMEOBJECT_H
#include "GameObject.h"
class EnemyGameObject : public GameObject
{
public:
	EnemyGameObject();
  virtual void initialize() override;
  virtual void shutdown() override;
  virtual void tick(float dt) override;
  virtual void render() override;
  virtual void physicsCallback(std::shared_ptr<GameObject> otherObject) override;
  int getDamage() { return m_damage; };
private:
  int m_health = 3;
  int m_damage = 2;
};

#endif // !ENEMYGAMEOBJECT_H
