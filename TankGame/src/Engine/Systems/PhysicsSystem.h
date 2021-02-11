#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "System.h"
#include "../Messages/MessageManager.h"
#include <string>

class PhysicsSystem : virtual public System, MessageNode
{
public:
  PhysicsSystem(std::shared_ptr<MessageManager> messageManager) : MessageNode(&(*messageManager)) {};
  virtual void initialize() override;
  virtual void tick(float dt) override;
  virtual void render() override;
  virtual void shutdown() override;
  virtual const std::string getSystemName() const override { return m_systemName; };

private:
  bool circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh);
  std::string m_systemName = "physics system";
};

#endif
