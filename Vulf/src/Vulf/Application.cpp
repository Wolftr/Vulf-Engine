#include "vulfpch.h"
#include "Application.h"

#include "Vulf/Events/ApplicationEvent.h"
#include "Vulf/Log.h"

#include <GLFW/glfw3.h>

namespace Vulf {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window -> OnUpdate();
		}
	}
}