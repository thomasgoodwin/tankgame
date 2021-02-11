#ifndef GAMEPLAYSYSTEM_H
#define GAMEPLAYSYSTEM_H

#include "System.h"
#include "../Messages/MessageManager.h"
#include "../Games/Game.h"

class GameplaySystem : public System, MessageNode
{
public:
  GameplaySystem(std::shared_ptr<MessageManager> messageManager) : MessageNode(&(*messageManager)) {};
  virtual void initialize() override;
  virtual void tick(float dt) override;
  virtual void render() override;
  virtual void shutdown() override;
  virtual const std::string getSystemName() const override { return m_systemName; };
  void removePlayerFromCurrentGame(unsigned int playerID) { m_games[m_currentGame]->eliminatePlayer(playerID); };
  void setNextGame(int newGame);
  enum Games
  {
    Tanks
  };
private: // should have a container of levels but we're just going to have 1 level anyway
  std::string m_systemName = "gameplay system";
  std::vector<std::shared_ptr<Game>> m_games;
  int m_currentGame = 0;
};

#endif