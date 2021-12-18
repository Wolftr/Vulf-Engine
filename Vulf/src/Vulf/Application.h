#pragma once

#include <vulfpch.h>
#include "Core.h"
#include "Events/Event.h"
#include "Vulf/Events/ApplicationEvent.h"

#include "Window.h"

namespace Vulf {

	class VULF_API Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Defined in client
	Application* CreateApplication();
}

