#include "GameObject.h"
#include "../Engine.h"
#include "../Components/Component.h"
#include "../Systems/SFMLSystem.h"


GameObject::GameObject()
{
}

void GameObject::initialize()
{
 
}

void GameObject::shutdown()
{
  for (auto& component : m_components)
  {
    component->shutdown();
  }
}

void GameObject::tick(float dt)
{
  for (auto& component : m_components)
  {
    component->tick(dt);
  }
}

void GameObject::render()
{
  auto graphicsWindow = Engine::get().getSFMLSystem().getWindow();
  graphicsWindow->draw(getShape());

  for (auto& component : m_components)
  {
    component->render();
  }
}

void GameObject::addComponent(const std::shared_ptr<Component>& component)
{
  m_components.push_back(component);
  component->setParent(this);
  component->initialize();
}

void GameObject::removeComponent(const std::shared_ptr<Component>& componentToRemove)
{
  auto itr = std::find(m_components.begin(), m_components.end(), componentToRemove);

  if (itr != m_components.end())
  {
    (*itr)->shutdown();
    m_components.erase(itr);
  }
}

std::weak_ptr<Component> GameObject::lockComponent(const Component* component) const
{
  for (const auto& comp : m_components)
  {
    if (comp.get() == component)
    {
      return comp;
    }
  }
  return std::weak_ptr<Component>();
}

void GameObject::markObjectForDestruction()
{
  m_isMarkedForDestruction = !m_isMarkedForDestruction;
}

void GameObject::disable()
{
  m_isDisabled = !m_isDisabled;
}

bool GameObject::isDisabled()
{
  return m_isDisabled;
}

void GameObject::setPos(sf::Vector2f newPos)
{
  m_shape.setPosition(newPos);
}

void GameObject::setSize(sf::Vector2f newSize)
{
  m_shape.setSize(newSize);
}