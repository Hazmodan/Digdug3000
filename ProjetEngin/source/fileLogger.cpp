#include "fileLogger.h"
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#include <stdio.h>


ProjetEngin::FileLogger::FileLogger()
{
	MyFile = std::ofstream("digdugengine.txt");
}

ProjetEngin::FileLogger::~FileLogger()
{
	MyFile.close();
}

void ProjetEngin::FileLogger::Log(const char* message)
{
	MyFile << message << std::endl;
}
