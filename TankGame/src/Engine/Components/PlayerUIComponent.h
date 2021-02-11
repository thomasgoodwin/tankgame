#ifndef PLAYERUICOMPONENT_H
#define PLAYERUICOMPONENT_H
#include "../Components/Component.h"
#include "SFML/Graphics.hpp"

class PlayerUIComponent : public Component
{
public:
  PlayerUIComponent();
  virtual void initialize() override;
  virtual void shutdown() override;
  virtual void tick(float dt) override;
  virtual void render() override;
  virtual const std::string getTypename() const { return "player ui component"; };
private:
  std::shared_ptr<sf::Text> m_playerHealth;
  std::shared_ptr<sf::Text> m_playerShotCooldown;

};


#endif