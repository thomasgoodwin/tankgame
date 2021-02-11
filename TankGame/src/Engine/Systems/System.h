#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
class System 
{
public:
  virtual ~System() = default;
  virtual void initialize() = 0;
  virtual void tick(float dt) = 0;
  virtual const std::string getSystemName() const = 0;
  virtual void render() = 0;
  virtual void shutdown() = 0;
};

#endif