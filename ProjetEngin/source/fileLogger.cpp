#include "fileLogger.h"
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#include <stdio.h>

/// <summary>
/// Constructor for the file logger
/// </summary>
ProjetEngin::FileLogger::FileLogger()
{
	MyFile = std::ofstream("digdugengine.txt");
}

/// <summary>
/// Destructor for the file logger
/// </summary>
ProjetEngin::FileLogger::~FileLogger()
{
	MyFile.close();
}

/// <summary>
/// Message to be sent to the file logger
/// </summary>
/// <param name="message"></param>
void ProjetEngin::FileLogger::Log(const std::string& message)
{
	MyFile << message << std::endl;
}
