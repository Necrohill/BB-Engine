#include <BBEngine.h>

class Sandbox : public BBEngine::Application
{
public :
	Sandbox() {

	}
	~Sandbox() {

	}
};

BBEngine::Application* BBEngine::CreateApplication() {
	return new Sandbox();
}