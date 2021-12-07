#pragma once

#ifdef VULF_PLATFORM_WINDOWS
extern Vulf::Application* Vulf::CreateApplication();

int main() {
	printf("Vulf\n");
	auto app = Vulf::CreateApplication();
	app->Run();
	delete app;
}
#endif