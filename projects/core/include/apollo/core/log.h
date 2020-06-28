#ifndef apollo_log_h__
#define apollo_log_h__

#pragma warning(push)
#pragma warning(disable: 4251)

#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

class Log
{
	public:
		static std::shared_ptr<spdlog::logger>& getCoreLogger() noexcept;
		static std::shared_ptr<spdlog::logger>& getClientLogger() noexcept;

	private:
		Log();

		struct LogData;
		static LogData* _data;

		static Log _instance;
};

// Core log macros
#define APOLLO_INTERNAL_TRACE(...)		Log::getCoreLogger()->trace(__VA_ARGS__)
#define APOLLO_INTERNAL_INFO(...)		Log::getCoreLogger()->info(__VA_ARGS__)
#define APOLLO_INTERNAL_WARN(...)		Log::getCoreLogger()->warn(__VA_ARGS__)
#define APOLLO_INTERNAL_ERROR(...)		Log::getCoreLogger()->error(__VA_ARGS__)
#define APOLLO_INTERNAL_CRITICAL(...)	Log::getCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define APOLLO_TRACE(...)				Log::getClientLogger()->trace(__VA_ARGS__)
#define APOLLO_INFO(...)				Log::getClientLogger()->info(__VA_ARGS__)
#define APOLLO_WARN(...)				Log::getClientLogger()->warn(__VA_ARGS__)
#define APOLLO_ERROR(...)				Log::getClientLogger()->error(__VA_ARGS__)
#define APOLLO_CRITICAL(...)			Log::getClientLogger()->critical(__VA_ARGS__)

#pragma warning(pop)

#endif // apollo_log_h__