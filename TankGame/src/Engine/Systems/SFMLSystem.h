#ifndef SFMLSYSTEM_H
#define SFMLSYSTEM_H

#include <SFML/Graphics.hpp>
#include "System.h"
#include "../Messages/MessageManager.h"
#include <vector>
#include <memory>

class SFMLSystem;

class SFMLSystem : public System, MessageNode
{
public:
  SFMLSystem(std::shared_ptr<MessageManager> messageManager) : MessageNode(&(*messageManager)) {};
  virtual void initialize() override;
  virtual void tick(float dt) override;
  virtual void render() override;
  virtual void shutdown() override;
  std::shared_ptr<sf::RenderWindow> getWindow();
  virtual const std::string getSystemName() const override { return "sfml system"; };
  std::shared_ptr<sf::Font> getFont() { return m_font; };
private:
  std::shared_ptr<sf::RenderWindow> m_window;
  std::shared_ptr<sf::Vector2i> m_centerWindow;
  std::shared_ptr<sf::Event> m_event;
  std::shared_ptr<sf::Font> m_font;
};
#endif