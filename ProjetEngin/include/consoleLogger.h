#pragma once
#include "iLogger.h"
#include <iostream>

namespace ProjetEngin {

class ConsoleLogger : public ILogger {
public:
	ConsoleLogger();
	~ConsoleLogger();
	virtual void Log(const char* message) override;

private:
};

}
