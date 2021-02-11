#ifndef TANKGAME_H
#define TANKGAME_H
#include "Game.h"


class TankGame : public Game
{
public:
	virtual void initialize() override;
	virtual void begin() override;
	virtual void tick(float dt) override;
	virtual void render() override;
	virtual void end() override;
	virtual void shutdown() override;

private:

};
#endif // !TANKGAME_H


