#include "PlayerUIComponent.h"
#include "../Engine.h"
#include "../Systems/SFMLSystem.h"
#include "../GameObjects/GameObject.h"
#include "../GameObjects/PlayerGameObject.h"
#include "../Components/LaserGunComponent.h"

PlayerUIComponent::PlayerUIComponent()
{
	m_playerHealth = std::make_shared<sf::Text>();
	m_playerShotCooldown = std::make_shared<sf::Text>();
}
void PlayerUIComponent::initialize() 
{
	m_playerHealth->setFont(*(Engine::get().getSFMLSystem().getFont()));
	m_playerHealth->setCharacterSize(20);
	
	m_playerShotCooldown->setFont(*(Engine::get().getSFMLSystem().getFont()));
	m_playerShotCooldown->setCharacterSize(15);
}
void PlayerUIComponent::shutdown()
{

}
void PlayerUIComponent::tick(float dt)
{

}
void PlayerUIComponent::render()
{
	auto window = Engine::get().getSFMLSystem().getWindow();
	auto player = dynamic_cast<PlayerGameObject*>(getParent());
	int health = player->getHealth();
	if (player->getPlayerID() == 1)
	{
		m_playerHealth->setPosition(sf::Vector2f(100, 0));
	}
	else
	{
		m_playerHealth->setPosition(sf::Vector2f(500, 0));
	}
	m_playerHealth->setString("Player " + std::to_string(player->getPlayerID()) + " Health: " + std::to_string(health));
	window->draw(*m_playerHealth);

	std::vector<std::shared_ptr<LaserGunComponent>> laserGun;
	player->getComponents<LaserGunComponent>(laserGun);
	float gunCooldown = laserGun[0]->getCooldown();
	m_playerShotCooldown->setString("Gun Cooldown: " + std::to_string(gunCooldown));
	if (gunCooldown != 0) // shot not ready
	{
		m_playerShotCooldown->setFillColor(sf::Color::Red);
	}
	else // shot ready
	{
		m_playerShotCooldown->setFillColor(sf::Color::Green);
	}
	if (player->getPlayerID() == 1)
	{
		m_playerShotCooldown->setPosition(sf::Vector2f(100, 30));
		m_playerHealth->setFillColor(sf::Color::Blue);
	}
	else
	{
		m_playerShotCooldown->setPosition(sf::Vector2f(500, 30));
		m_playerHealth->setFillColor(sf::Color::Yellow);
	}
	window->draw(*m_playerShotCooldown);
}