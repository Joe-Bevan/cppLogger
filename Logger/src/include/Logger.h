#pragma once
#include <Windows.h>
#include <iostream>
#include <Bitset>
#include <string>

namespace Logger {
	namespace {
		std::bitset<3> mSet(7); // Default value of 7 (111 in binary) to enable all logs to be displayed.
		HANDLE  hConsole;

		void ResetConsoleColor() {
			SetConsoleTextAttribute(hConsole, 15);
		}
	}

	enum logStates {		// Binary:
		LOG_MSG = 1,		// 001
		LOG_WARN = 2,		// 010
		LOG_ERR	= 4			// 100
	};


	void Init(HANDLE handle)
	{
		if (handle)
			hConsole = handle; // Grab handle to console (so we can change colors)
		else
			std::cout << "NO HANDLE TO CONSOLE PROVIDED.\nDid you pass in 'GetStdHandle(STD_OUTPUT_HANDLE)'?" << std::endl;
	}
	

	void SetLogLevel(int state) {
		mSet = state;
	}


	//
	// Standard Console output
	//

	// Message logging functions (Green text)
	void LogMsg(const char* msg) {
		if (mSet.test(0)) {
			SetConsoleTextAttribute(hConsole, 10); 
			std::cout << "[MSG]: " << msg << std::endl;
			ResetConsoleColor();
		}
	}

	template<typename T>
	void LogMsg(const char* msg, T obj) {
		if (mSet.test(0)) {
			SetConsoleTextAttribute(hConsole, 10); 
			std::cout << "[MSG]: " << msg << " | " << "[OBJ]: " << obj << std::endl;
			ResetConsoleColor();
		}
	}

	template<typename T>
	void LogMsg(const char* msg, T objs[], size_t size) {
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


	// Warning logging functions (Yellow text)
	void LogWarn(const char* warnMsg) {
		if (mSet.test(1)) {
			SetConsoleTextAttribute(hConsole, 14); 
			std::cout << "[WARN]: " << warnMsg << std::endl;
			ResetConsoleColor();
		}
	}

	template<typename T>
	void LogWarn(const char* warnMsg, T obj) {
		if (mSet.test(0)) {
			SetConsoleTextAttribute(hConsole, 14); 
			std::cout << "[WARN]: " << warnMsg << " | " << "[OBJ]: " << obj << std::endl;
			ResetConsoleColor();
		}
	}

	template<typename T>
	void LogWarn(const char* warnMsg, T objs[], size_t size) {
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


	// Error logging functions (Red text)
	void LogError(const char* errMsg) {
		if (mSet.test(2)) {
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "[ERROR]: " << errMsg << std::endl;
			ResetConsoleColor();
		}
	}

	template<typename T>
	void LogError(const char* errMsg, T obj) {
		if (mSet.test(0)) {
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "[ERR]: " << errMsg << " | " << "[OBJ]: " << obj << std::endl;
			ResetConsoleColor();
		}
	}

	template<typename T>
	void LogError(const char* errMsg, T objs[], size_t size) {
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


	//
	// Return the string for custom output (e.g. Custom debug pannel)
	// 
	std::string GetLogMsg(const char* msg) {
		if (mSet.test(0)) {
			std::string msg(msg);
			return "[MSG]: " + msg + "\n";
		}
	}

	std::string GetLogWarn(const char* warnMsg) {
		if (mSet.test(1)) {
			std::string wMsg(warnMsg);
			return "[WARN]: " + wMsg + "\n";

		}
	}

	std::string GetLogError(const char* errMsg) {
		if (mSet.test(2)) {
			std::string eMsg(errMsg);
			return "[ERROR]: " + eMsg + "\n";
		}
	}


}
