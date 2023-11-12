#include "consoleLogger.h"
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#include <stdio.h>
#include <iostream>

HANDLE hConsole;

/// <summary>
/// Constructor for the console logger
/// </summary>
ProjetEngin::ConsoleLogger::ConsoleLogger()
{
	AllocConsole();
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	if (_r != 0)
	{
		std::cout << "erreur avec la console" << std::endl;
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

/// <summary>
/// Destructor for the console logger
/// </summary>
ProjetEngin::ConsoleLogger::~ConsoleLogger()
{
	//If the function fails, the return value is zero.
	int _r = FreeConsole();
	if (_r == 0)
	{
		// Fail message...
		std::cout << "erreur avec la console" << std::endl;
	}
}

/// <summary>
/// Message to be sent to the console
/// </summary>
/// <param name="message"></param>
void ProjetEngin::ConsoleLogger::Log(const std::string& message)
{
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << message << std::endl;
}

/// <summary>
/// Floats to be sent to the console
/// </summary>
/// <param name="numbers"></param>
void ProjetEngin::ConsoleLogger::Log(const float numbers)
{
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << numbers << std::endl;
}

/// <summary>
/// errors sent to the console
/// </summary>
/// <param name="message"></param>
void ProjetEngin::ConsoleLogger::LogError(const std::string& message)
{
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "ERROR : " << message << std::endl;
}

/// <summary>
/// warnings sent to the console
/// </summary>
/// <param name="message"></param>
void ProjetEngin::ConsoleLogger::LogWarning(const std::string& message)
{
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "WARNING : " << message << std::endl;
}