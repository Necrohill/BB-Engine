#include "BBPCH.h"
#include "Application.h"
#include "BBEngine\Events\ApplicationEvent.h"
#include "BBEngine\Log.h"

namespace BBEngine {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResiceEvent e(1280, 720);
		BBEngine_Trace(e);

		while (true);
	}

}