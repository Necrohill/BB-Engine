#pragma once

#include "Event.h"

namespace BBEngine {
	class BBEngine_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: mouseX(x), mouseY(y) {}

		inline float GetX() const { return mouseX; }
		inline float GetY() const { return mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CATEGORY(Cat_Mouse | Cat_Input)

	protected:
		float mouseX, mouseY;
	};

	class BBEngine_API MouseScrooledEvent : public Event {
	public:
		MouseScrooledEvent(float x, float y)
			: mouseX(x), mouseY(y) {}

		inline float GetX() const { return mouseX; }
		inline float GetY() const { return mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrooledEvent: " << mouseX << ", " << mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrooled)
		EVENT_CATEGORY(Cat_Mouse | Cat_Input)

	protected:
		float mouseX;
		float mouseY;
	};

	class BBEngine_API MouseButtonEvent : public Event {
	public:

		inline int GetMouseButton() const { return mouseButton; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonEvent: " << mouseButton;
			return ss.str();
		}

		EVENT_CATEGORY(Cat_Mouse | Cat_Input)

	protected:
		MouseButtonEvent(int button)
			: mouseButton(button) {}

		int mouseButton;
	};

	class BBEngine_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << mouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	protected:
	};

	class BBEngine_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << mouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	protected:
	};
}