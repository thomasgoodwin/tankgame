#ifndef GAME_H
#define GAME_H
#include <list>
#include <algorithm>
#include "../GameObjects/GameObject.h"

class Game
{
public:
	virtual void initialize() = 0;
	virtual void begin() = 0;
	virtual void tick(float dt) = 0;
	virtual void render() = 0;
	virtual void end() = 0;
	virtual void shutdown() = 0;
	bool isRunning() { return m_isRunning; };
	void isRunning(bool running) { m_isRunning = running; };
	virtual void eliminatePlayer(unsigned int player) { m_players.remove(player); };
	virtual void addPlayer(unsigned int newPlayer) { m_players.push_front(newPlayer); };
private:
	bool m_isRunning = false;
	std::list<unsigned int> m_players;
};

#endif