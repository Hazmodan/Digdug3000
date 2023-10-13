#pragma once

namespace ProjetEngin {

class ILogger {
public:
	virtual ~ILogger() = default; 
	virtual void Log(const char* message) = 0;

private:

};

}

