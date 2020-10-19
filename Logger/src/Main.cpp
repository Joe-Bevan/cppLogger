#include "include/Logger.h"


int main() {

	// Setup
	Logger::Init(GetStdHandle(STD_OUTPUT_HANDLE)); // Setup for color GetStdHandle(STD_OUTPUT_HANDLE)
	Logger::SetLogLevel(LogStates::LOG_ERR | LogStates::LOG_WARN | LogStates::LOG_MSG); // you can OR multiple flags together
	
	// Simple logging messages
	Logger::LogMsg("Hello msg");
	Logger::LogWarn("Hello warn");
	Logger::LogError("Hello error");
	
	std::cout << std::endl;
	
	// Return the string for a custom output system
	std::cout << Logger::GetLogMsg("Hello msg"); 
	std::cout << Logger::GetLogWarn("Hello warn"); 
	std::cout << Logger::GetLogError("Hello error"); 
	
	std::cout << std::endl;
	
	// Logging an primitive type
	int i = 7;
	Logger::LogMsg("lvalue int", i);
	Logger::LogMsg("rvalue int", 5);
	
	// Logging arrays of primitives
	int iarr[] = { 1,2,3 };
	Logger::LogMsg("iarr", iarr, 3);



	std::cin.get();
	return 0;
}