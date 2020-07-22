#pragma once

#include "Event.h"

namespace BBEngine {

	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return keyCode; }

		EVENT_CATEGORY(Cat_Keyboard | Cat_Input)

	protected:
		KeyEvent(int code)
			: keyCode(code) {}

		int keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int code, int repeat)
			: KeyEvent(code), repeatCount(repeat) {}

		inline int GetRepeatCount() const { return repeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	protected:

		int repeatCount;

	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int code)
			: KeyEvent(code) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}