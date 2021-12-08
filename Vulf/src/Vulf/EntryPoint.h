#pragma once

#ifdef VULF_PLATFORM_WINDOWS
extern Vulf::Application* Vulf::CreateApplication();

int main() {
	Vulf::Log::Init();
	VULF_CORE_INFO ("Initialized Core Log");
	VULF_INFO ("Initialized Client Log");

	printf("Vulf\n");
	auto app = Vulf::CreateApplication();
	app->Run();
	delete app;
}
#endif