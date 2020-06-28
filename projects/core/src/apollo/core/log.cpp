#include <apollo/core/log.h>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <filesystem>

Log Log::_instance;

struct Log::LogData
{
	std::shared_ptr<spdlog::logger> coreLogger;
	std::shared_ptr<spdlog::logger> clientLogger;
};

Log::LogData* Log::_data;

Log::Log()
{
	_data = new Log::LogData();

	std::filesystem::path cwd = std::filesystem::current_path();

	const auto coreFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(cwd.string() + "/core.log", true);
	const auto clientFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(cwd.string() + "/client.log", true);
	const auto combinedFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(cwd.string() + "/console.log", true);

	_data->coreLogger = spdlog::stdout_color_mt("Apollo");
	_data->clientLogger = spdlog::stdout_color_mt("Client");

	_data->coreLogger->sinks().push_back(coreFileSink);
	_data->coreLogger->sinks().push_back(combinedFileSink);
	_data->coreLogger->flush_on(spdlog::level::trace);

	_data->clientLogger->sinks().push_back(clientFileSink);
	_data->clientLogger->sinks().push_back(combinedFileSink);
	_data->clientLogger->flush_on(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger>& Log::getCoreLogger() noexcept
{
	return _data->coreLogger;
}

std::shared_ptr<spdlog::logger>& Log::getClientLogger() noexcept
{
	return _data->clientLogger;
}
