#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class GameObject;

class Component
{
public:
  virtual void initialize() = 0;
  virtual void shutdown() = 0;
  virtual void tick(float dt) = 0;
  virtual void render() = 0;

  virtual const std::string getTypename() const = 0;

  GameObject* getParent() const;
  void setParent(GameObject* m_parent);

private:
  GameObject* m_parent = nullptr;
};

#endif