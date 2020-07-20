#pragma once
#include "Core.h"

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