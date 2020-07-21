#pragma once

#ifdef BB_PLATFORM_WINDOWNS

extern BBEngine::Application* BBEngine::CreateApplication();

int main(int argc, char** argv) {

	BBEngine::Log::Init();

	BBEngine_Core_Info("log Started");

	auto app = BBEngine::CreateApplication();
	BBEngine_Info("App running");
	app->Run();
	delete app;
}

#endif // BBEngine_Platform_Windows