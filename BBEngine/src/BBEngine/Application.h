#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace BBEngine {

	class BBEngine_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();

}