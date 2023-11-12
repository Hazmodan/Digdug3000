#pragma once
#include "iLogger.h"

namespace ProjetEngin {

/// <summary>
/// Console logger, taking information from ILogger
/// </summary>
class ConsoleLogger : public ILogger {
public:
	ConsoleLogger();
	~ConsoleLogger();
	virtual void Log(const std::string& message) override;
	virtual void Log(const float numbers) override;

	virtual void LogError(const std::string& message) override;
	virtual void LogWarning(const std::string& message) override;
};

}
