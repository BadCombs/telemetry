#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

#include "fsm.h"

using namespace std;
using namespace std::chrono;

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
	
	fstream output;

	// Flags
	bool write, start, end;
	
	// Time start
	steady_clock::time_point start_time, stop_time;
	start_time = steady_clock::now();

	// Main loop
	while ((len = can_receive(buffer)) > 0) {
		// cout << len << "\t" << buffer << endl;
		machine.parse_entry(buffer, len, write, start, end);
		
		// Calculate time in milliseconds
		stop_time = steady_clock::now();
		duration<double> time_span = stop_time - start_time;

		if (start) {
			output.open(
				"session" + to_string(session_count) + ".txt", 
				fstream::out
			);
		}
		else if (end) {
			output.close();
			session_count++;
		}
		else if (write) {
			cout << "(" << (uint64_t)(time_span.count()*1000) 
			<< ") "	<< buffer << endl; 
			output << "(" << (uint64_t)(time_span.count()*1000) 
			<< ") " << buffer << endl;
		}
	}
	
	output.close();
	close_can();

    return 0;
}
