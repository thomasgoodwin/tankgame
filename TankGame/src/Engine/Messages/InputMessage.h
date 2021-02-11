#ifndef INPUTMESSAGE_H
#define INPUTMESSAGE_H

#include "Message.h"
#include <SFML/Graphics.hpp>

class InputMessage : public Message
{
public:
	InputMessage(int keystroke)
	{
		m_keyStroke = keystroke;
	}
	int m_keyStroke;
};

#endif