#ifndef WALLGAMEOBJECT_H
#define WALLGAMEOBJECT_H
#include "GameObject.h"


class WallGameObject : public GameObject
{
public:
  WallGameObject(int);
  virtual void initialize() override;
  virtual void shutdown() override;
  virtual void tick(float dt) override;
  virtual void render() override;
  virtual void physicsCallback(std::shared_ptr<GameObject> otherObject) override;
private:
  int m_health;
};

#endif // !ENEMYGAMEOBJECT_H
