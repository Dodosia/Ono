#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Ono
{
	class ONO_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
	};
}

#define ONO_CORE_TRACE(...) ::Ono::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ONO_CORE_INFO(...)  ::Ono::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ONO_CORE_WARN(...)  ::Ono::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ONO_CORE_ERROR(...) ::Ono::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ONO_CORE_FATAL(...) ::Ono::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define ONO_TRACE(...) ::Ono::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ONO_INFO(...)  ::Ono::Log::GetClientLogger()->info(__VA_ARGS__)
#define ONO_WARN(...)  ::Ono::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ONO_ERROR(...) ::Ono::Log::GetClientLogger()->error(__VA_ARGS__)
#define ONO_FATAL(...) ::Ono::Log::GetClientLogger()->fatal(__VA_ARGS__)

