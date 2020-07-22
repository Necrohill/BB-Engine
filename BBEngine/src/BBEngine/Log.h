#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace BBEngine {

	class BBEngine_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}

#define BBEngine_Core_Trace(...) ::BBEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BBEngine_Core_Info(...) ::BBEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BBEngine_Core_Warn(...) ::BBEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BBEngine_Core_Error(...) ::BBEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BBEngine_Core_Fatal(...) ::BBEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define BBEngine_Trace(...) ::BBEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BBEngine_Info(...) ::BBEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define BBEngine_Warn(...) ::BBEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BBEngine_Error(...) ::BBEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define BBEngine_Fatal(...) ::BBEngine::Log::GetClientLogger()->critical(__VA_ARGS__)