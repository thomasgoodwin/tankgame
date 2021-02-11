#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <unordered_map>

class Message
{
public:
  Message() { }
  virtual ~Message() { }
  std::unordered_map<std::string, std::string> m_information;
};

#endif