#include "consoleLogger.h"
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#include <stdio.h>


ProjetEngin::ConsoleLogger::ConsoleLogger()
{
	AllocConsole();
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
}

ProjetEngin::ConsoleLogger::~ConsoleLogger()
{
	FreeConsole();
}

void ProjetEngin::ConsoleLogger::Log(const char* message)
{
	std::cout << message << std::endl;
}
