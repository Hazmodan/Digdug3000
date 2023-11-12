#pragma once
#include <string>

namespace ProjetEngin 
{
	class ILogger
	{
	public:
		virtual ~ILogger() = default;

		virtual void Log(const std::string& message) = 0;
		virtual void Log(const float numbers) = 0;
		virtual void LogError(const std::string& message) = 0;
		virtual void LogWarning(const std::string& message) = 0;
	};
}

