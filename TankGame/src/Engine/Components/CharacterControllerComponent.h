#ifndef PLAYERINPUTCOMPONENT_H
#define PLAYERINPUTCOMPONENT_H

#include "../Components/Component.h"
#include "SFML/Graphics.hpp"


class CharacterControllerComponent : public Component
{
public:
	CharacterControllerComponent();
	~CharacterControllerComponent();
	virtual void initialize() override;
	virtual void shutdown() override;
	virtual void tick(float dt) override;
	virtual void render() override;
	bool checkBounds(sf::Vector2f movementDelta);
	virtual const std::string getTypename() const override { return "character controller component"; };
private:
	sf::Vector2f m_directionVector;
	float m_rotationSpeed = 100.0f;
	float m_moveSpeed = 180.0f;
};

#endif // !PLAYERINPUTCOMPONENT_H
