#include "include/Logger.h"


int main() {

	// Setup
	Logger::Init(GetStdHandle(STD_OUTPUT_HANDLE)); // Setup for color GetStdHandle(STD_OUTPUT_HANDLE)
	Logger::SetLogLevel(LogStates::LOG_ERR | LogStates::LOG_WARN | LogStates::LOG_MSG); // you can OR multiple flags together
	
	// Simple logging messages
	Logger::LogMsg("Hello msg");
	Logger::LogWarn("Hello warn");
	Logger::LogError("Hello error", __FILE__);
	
	std::cout << std::endl;
	
	// Logging an primitive type
	int i = 7;
	Logger::LogMsg("lvalue int", i, __FILE__);
	Logger::LogMsg("rvalue int", 5, __FILE__);
	
	// Logging arrays of primitives
	int iarr[] = { 1,2,3 };
	Logger::LogMsg("iarr", iarr, 3, __FILE__);



	std::cin.get();
	return 0;
}