#pragma once

#include "Event.h"

#include <sstream>

namespace BBEngine {


	class BBEngine_API WindowResiceEvent : public Event
	{
	public:
		WindowResiceEvent(unsigned int width, unsigned int height)
			: tWidth(width), tHeight(height) {}

		inline unsigned int GetWidth() const { return tWidth; }
		inline unsigned int GetHeight() const { return tHeight; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResiceEvent: " << tWidth << ", " << tHeight;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResice)
		EVENT_CATEGORY(Cat_Application)

	private:
		unsigned int tWidth, tHeight;
	};

	class BBEngine_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}


		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CATEGORY(Cat_Application)

	};

	class BBEngine_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}


		EVENT_CLASS_TYPE(AppTick)
		EVENT_CATEGORY(Cat_Application)

	};

	class BBEngine_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}


		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CATEGORY(Cat_Application)

	};

	class BBEngine_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}


		EVENT_CLASS_TYPE(AppRender)
		EVENT_CATEGORY(Cat_Application)

	};
}