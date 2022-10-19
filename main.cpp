#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

#include "fsm.h"

using namespace std;

extern "C"{
    #include "fake_receiver.h"
}

int main(void){
    cout << "Welcome to Project 2" << endl;
	
	open_can("candump.log");
	
	
	fsm machine;
	int len;
	char buffer[MAX_CAN_MESSAGE_SIZE];
	int session_count = 1;
	
	std::fstream output;

	// Flags
	bool write, start, end;
	
	// Time start
	//time_t start = std::time(NULL);
	
	// Main loop
	while ((len = can_receive(buffer)) > 0) {
		//std::cout << len << "\t" << buffer << std::endl;
		machine.parse_entry(buffer, len, write, start, end);

		if (write) {
			//std::cout << "(" << time(NULL) << ") " << buffer << std::endl; 
			output << "(" << time(NULL) << ") " << buffer << std::endl; 
		}
		else if (start) {
			//std::cout << "New session started." << std::endl;
			output.open(
				"session" + std::to_string(session_count) + ".txt", 
				std::fstream::out
			);
		}
		else if (end) {
			//std::cout << "Previous session closed." << std::endl;
			output.close();
			session_count++;
		}
	}
	
	output.close();
	close_can();

    return 0;
}
