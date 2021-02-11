#include "Component.h"
#include "../GameObjects/GameObject.h"

GameObject* Component::getParent() const
{
	return m_parent;
}

void Component::setParent(GameObject* parent)
{
	m_parent = parent;
}