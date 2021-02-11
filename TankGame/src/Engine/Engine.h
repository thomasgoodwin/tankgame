#ifndef ENGINE_H
#define ENGINE_H

#define NUM_SYSTEMS 4
#include "Systems/System.h"
#include <chrono>
#include <ctime> 
#include <vector>
#include <memory>
#include <array>

class MessageManager;
class SFMLSystem;
class GameObjectSystem;
class GameplaySystem;
class PhysicsSystem;

class Engine
{
public:
	~Engine();
	void initialize();
	void gameLoop();
	void shutdown();
	void stopGame();
	static SFMLSystem& getSFMLSystem();
	static GameObjectSystem& getGameObjectSystem();
	static GameplaySystem& getGameplaySystem();
	static PhysicsSystem& getPhysicsSystem();
	static MessageManager& getMessageManager();
	static std::shared_ptr<MessageManager> getSharedMessageManager();

	bool gameIsRunning() { return m_gameIsRunning; };
	static Engine& get()
	{
		static Engine _instance;
		return _instance;
	}

private:
	std::shared_ptr<MessageManager> m_messageManager;
	Engine();
	static Engine _instance;

	void tick(float dt);
	void render();
	std::array<std::unique_ptr<System>, NUM_SYSTEMS> m_allSystems;
	float m_deltaTime;
	bool m_gameIsRunning = true;
	std::chrono::system_clock::time_point m_currentTime;
};

#endif