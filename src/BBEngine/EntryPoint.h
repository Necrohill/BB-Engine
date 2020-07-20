#pragma once

#ifdef BB_PLATFORM_WINDOWNS

extern BBEngine::Application* BBEngine::CreateApplication();

int main(int argc, char** argv) {

	auto app = BBEngine::CreateApplication();

	app->Run();

	delete app;
}

#endif // BBEngine_Platform_Windows
