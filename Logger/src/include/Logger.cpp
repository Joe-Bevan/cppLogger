#include "Logger.h"

std::bitset<3> Logger::mSet = 7; // Default value of 7 (111 in binary) to enable all logs to be displayed.
HANDLE Logger::hConsole = NULL;

void Logger::Init(HANDLE handle)
{

	if (handle)
		hConsole = handle; // Grab handle to console (so we can change colors)
	else
		std::cout << "NO HANDLE TO CONSOLE PROVIDED.\nDid you pass in 'GetStdHandle(STD_OUTPUT_HANDLE)'?" << std::endl;
}


void Logger::SetLogLevel(int state) {
	Logger::mSet = state;
}


void Logger::LogMsg(const char* msg) {
	if (mSet.test(0)) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[MSG]: " << msg << std::endl;
		ResetConsoleColor();
	}
}


void Logger::LogWarn(const char* warnMsg) {
	if (mSet.test(1)) {
		SetConsoleTextAttribute(hConsole, 14); 
		std::cout << "[WARN]: " << warnMsg << std::endl;
		ResetConsoleColor();
	}
}


void Logger::LogError(const char* errMsg) {
	if (mSet.test(2)) {
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "[ERROR]: " << errMsg << std::endl;
		ResetConsoleColor();
	}
}


std::string Logger::GetLogMsg(const char* msg) {
	if (mSet.test(0)) {
		std::string msg(msg);
		return "[MSG]: " + msg + "\n";
	}
}

std::string Logger::GetLogWarn(const char* warnMsg) {
	if (mSet.test(1)) {
		std::string wMsg(warnMsg);
		return "[WARN]: " + wMsg + "\n";

	}
}

std::string Logger::GetLogError(const char* errMsg) {
	if (mSet.test(2)) {
		std::string eMsg(errMsg);
		return "[ERROR]: " + eMsg + "\n";
	}
}