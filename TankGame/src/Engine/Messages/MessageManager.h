#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H
#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include "Message.h"


class MessageManager
{
public:
  MessageManager() {};
  ~MessageManager() {};

  void addReceiver(std::function<void(Message)> messageReceiver)
  {
    m_receivers.push_back(messageReceiver);
  }

  void sendMessage(Message message)
  {
    m_messages.push(message);
  }

  void notify()
  {
    while (!m_messages.empty()) {
      for (auto iter = m_receivers.begin(); iter != m_receivers.end(); iter++) {
        (*iter)(m_messages.front());
      }

      m_messages.pop();
    }
  }

private:
  std::vector<std::function<void(Message)>> m_receivers;
  std::queue<Message> m_messages;
};

class MessageNode
{
public:
  MessageNode(MessageManager* messageManager)
  {
    this->messageManager = messageManager;
    this->messageManager->addReceiver(this->getNotifyFunc());
  }

  virtual void update() {}
protected:
  MessageManager* messageManager;

  std::function<void(Message)> getNotifyFunc()
  {
    auto messageListener = [=](Message message) -> void {
      this->onNotify(message);
    };
    return messageListener;
  }

  void send(Message message)
  {
    messageManager->sendMessage(message);
  }

  virtual void onNotify(Message message)
  {

  }
};

#endif // !MESSAGEMANAGER_H