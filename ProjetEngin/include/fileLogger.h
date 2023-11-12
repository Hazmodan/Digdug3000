#pragma once
#include "iLogger.h"
#include <iostream>
#include <fstream>

namespace ProjetEngin {

	class FileLogger : public ILogger {
	public:
		FileLogger();
		~FileLogger();
		virtual void Log(const std::string& message) override;

	private:
		std::ofstream MyFile;
	};

}
