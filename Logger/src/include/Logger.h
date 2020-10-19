#pragma once
#include <Windows.h>
#include <iostream>
#include <Bitset>
#include <string>


enum LogStates {			// Binary:
	LOG_MSG =	1<<0,		// 001
	LOG_WARN =	1<<1,		// 010
	LOG_ERR =	1<<2		// 100
};

class Logger {
public:

	static void Init(HANDLE handle); // Takes a handle to the console window
	static void SetLogLevel(int state);

	// Standard message functions (Green text)
	static void LogMsg(const char* msg);
	template<typename T>
	static void LogMsg(const char* msg, T obj);
	template<typename T>
	static void LogMsg(const char* msg, T objs[], size_t size);

	// Warning logging functions (Yellow text)
	static void LogWarn(const char* warnMsg);
	template<typename T>
	static void LogWarn(const char* warnMsg, T obj);
	template<typename T>
	static void LogWarn(const char* warnMsg, T objs[], size_t size);

	// Error logging functions (Red text)
	static void LogError(const char* errMsg);
	template<typename T>
	static void LogError(const char* errMsg, T obj);
	template<typename T>
	static void LogError(const char* errMsg, T objs[], size_t size);
	
	// Get raw string for custom output
	static std::string GetLogMsg(const char* msg);
	static std::string GetLogWarn(const char* warnMsg);
	static std::string GetLogError(const char* errMsg);


private:
	static std::bitset<3> mSet; // Default value of 7 (111 in binary) to enable all logs to be displayed.
	static HANDLE hConsole;
	
	static void ResetConsoleColor() { SetConsoleTextAttribute(hConsole, 15); }

	// Deleted as its a purely static class and thus not needed
	Logger() = delete;
	~Logger() = delete;
	Logger(const Logger&) = delete;
};


/*
	=================================
	| TEMPLATE IMPLEMENTATION BELOW |
	=================================
*/
template<typename T>
void Logger::LogMsg(const char* msg, T obj) {
	if (mSet.test(0)) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[MSG]: " << msg << " | " << "[OBJ]: " << obj << std::endl;
		ResetConsoleColor();
	}
}

template<typename T>
void Logger::LogMsg(const char* msg, T objs[], size_t size) {
	if (mSet.test(0)) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "[MSG]: " << msg << " | [OBJ_ARR]: {";
		for (int i = 0; i < size; i++) {
			if (i != size - 1)
				std::cout << objs[i] << ", ";
			else
				std::cout << objs[i];
		}
		std::cout << '}' << std::endl;
		ResetConsoleColor();
	}
}
	
	

template<typename T>
void Logger::LogWarn(const char* warnMsg, T obj) {
	if (mSet.test(0)) {
		SetConsoleTextAttribute(hConsole, 14); 
		std::cout << "[WARN]: " << warnMsg << " | " << "[OBJ]: " << obj << std::endl;
		ResetConsoleColor();
	}
}

template<typename T>
void Logger::LogWarn(const char* warnMsg, T objs[], size_t size) {
	if (mSet.test(0)) {
		SetConsoleTextAttribute(hConsole, 14); 
		std::cout << "[WARN]: " << warnMsg << " | [OBJ_ARR]: { ";
		for (int i = 0; i < size; i++) {
			if (i != size - 1)
				std::cout << objs[i] << ", ";
			else
				std::cout << objs[i];
		}
		std::cout << " }" << std::endl;
		ResetConsoleColor();
	}
}



template<typename T>
void Logger::LogError(const char* errMsg, T obj) {
	if (mSet.test(0)) {
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "[ERR]: " << errMsg << " | " << "[OBJ]: " << obj << std::endl;
		ResetConsoleColor();
	}
}

template<typename T>
void Logger::LogError(const char* errMsg, T objs[], size_t size) {
	if (mSet.test(0)) {
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "[ERR]: " << errMsg << " | [OBJ_ARR]: { ";
		for (int i = 0; i < size; i++) {
			if (i != size - 1)
				std::cout << objs[i] << ", ";
			else
				std::cout << objs[i];
		}
		std::cout << " }" << std::endl;
		ResetConsoleColor();
	}
}
