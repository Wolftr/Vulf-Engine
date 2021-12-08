#include <Vulf.h>

class Sandbox : public Vulf::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Vulf::Application* Vulf::CreateApplication() {
	return new Sandbox();
}