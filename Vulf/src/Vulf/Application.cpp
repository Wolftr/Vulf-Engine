#include "Application.h"

#include "Vulf/Events/ApplicationEvent.h"
#include "Vulf/Log.h"

namespace Vulf {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		VULF_TRACE(e);
		while (true);
	}
}