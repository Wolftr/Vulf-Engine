#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Vulf {

	class VULF_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define VULF_CORE_TRACE(...)        ::Vulf::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define VULF_CORE_INFO(...)         ::Vulf::Log::GetCoreLogger()->info(__VA_ARGS__);
#define VULF_CORE_WARN(...)         ::Vulf::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define VULF_CORE_ERROR(...)        ::Vulf::Log::GetCoreLogger()->error(__VA_ARGS__);

// Client log macros
#define VULF_TRACE(...)             ::Vulf::Log::GetClientLogger()->trace(__VA_ARGS__);
#define VULF_INFO(...)              ::Vulf::Log::GetClientLogger()->info(__VA_ARGS__);
#define VULF_WARN(...)              ::Vulf::Log::GetClientLogger()->warn(__VA_ARGS__);
#define VULF_ERROR(...)             ::Vulf::Log::GetClientLogger()->error(__VA_ARGS__);