#pragma once
#include "BBPCH.h"

#include "BBEngine/Core.h"

namespace BBEngine {
	enum class EventType {
		None = 0,
		AppTick,
		AppUpdate,
		AppRender,
		KeyPressed,
		KeyReleased,
		MouseButtonPressed,
		MouseButtonReleased, 
		MouseMoved,
		MouseScrooled,
		WindowClose,
		WindowResice,
		WindowFocus,
		WindowLostFocus,
		WindowMoved
	};
	enum EventCategory {
		None = 0,
		Cat_Application		= BIT(0),
		Cat_Input			= BIT(1),
		Cat_Keyboard		= BIT(2),
		Cat_Mouse			= BIT(3),
		Cat_MouseButton		= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }
#define EVENT_CATEGORY(cat) virtual int GetCategoryFlags() const override { return cat; }

	class BBEngine_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory cat)
		{
			return GetCategoryFlags() & cat;
		}

	protected:
		bool handled = false;


	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: tEvent(event) {}

		template<typename T>
		bool Dispatche(EventFn<T> func) {
			if (tEvent.GetEventType() == T::GetStaticType()) {
				t.handled = func(*(T*)&tEvent);
				return true;
			}
			return false;
		}
	private:
		Event& tEvent;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) 
	{
		return os << e.ToString();
	}

}