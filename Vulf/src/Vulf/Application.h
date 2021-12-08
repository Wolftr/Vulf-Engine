#pragma once

#include "Core.h"

namespace Vulf {

	class VULF_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	// Defined in client
	Application* CreateApplication();
}

