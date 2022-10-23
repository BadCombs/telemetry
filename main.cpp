#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <set>
#include <iterator>

#include "fsm.h"
#include "id_info.h"


extern "C"{
    #include "fake_receiver.h"
}

int main(void){
    std::cout << "Welcome to Project 2" << std::endl;
	
	open_can("candump.log");
	
	
	fsm machine;
	int len;
	char buffer[MAX_CAN_MESSAGE_SIZE+1]; 	// 1 for \0 to avoid memory waste
											// while print message
	int session_count = 1;
	int statistics_count = 1;
	
	std::fstream output;
	std::fstream statistics_out;

	// Flags written by fsm
	bool write, start, end;
	
	// List of id_info for statistics
	uint16_t tmp_id;
	id_info tmp_id_info(0x1000);
	std::set<id_info> id_s;
	std::set<id_info>::iterator id_it;

	// Time start
	std::chrono::steady_clock::time_point start_time, stop_time, 
											last_rec_time;
	start_time = std::chrono::steady_clock::now();
	std::chrono::duration<double> time_span;
	uint64_t ms_since_start;

	// Main loop
	while ((len = can_receive(buffer)) > 0) {
		//std::cout << len << "\t" << buffer << std::endl;
		tmp_id = machine.parse_entry(buffer, len, 
									write, start, end);
		
		buffer[len] = '\0';

		// Calculate time in milliseconds
		stop_time = std::chrono::steady_clock::now();
		time_span = stop_time - start_time;
		ms_since_start = (uint64_t)(time_span.count()*1000);// Milliseconds 

		if (start) {
			// Open new session file
			output.open(
				"session" + std::to_string(session_count) + ".txt", 
				std::fstream::out
			);
			
			// Open new csv file
			statistics_out.open(
				"statistics" + std::to_string(statistics_count) + 
				".csv", std::fstream::out
			);
		}
		else if (end) {
			// Write on statistics file
			statistics_out << "ID,number_of_messages,mean_time\n";
			id_it = id_s.begin();
			while (id_it != id_s.end()) {
				statistics_out << *id_it << "\n";
				id_it++;
			}
			id_s.clear();

			output.close();
			statistics_out.close();

			session_count++;
			statistics_count++;
		}
		else if (write) {
			// Write on file
			/*std::cout << "(" << ms_since_start
					<< ") "	<< buffer << std::endl; */
			output << "(" <<  ms_since_start
					<< ") " << buffer << std::endl;
			
			// Update statistics
			id_it = id_s.find(tmp_id);
			// If elem not found
			if (id_it == id_s.end()) {
				tmp_id_info.reset();
				tmp_id_info.set_id(tmp_id);
				tmp_id_info.add(ms_since_start);
				id_s.insert(tmp_id_info);
			}
			else {
				id_it->add(ms_since_start);
			}
		}
	}
	
	// Write on statistics file
	statistics_out << "ID,number_of_messages,mean_time\n";
	id_it = id_s.begin();
	while (id_it != id_s.end()) {
		statistics_out << *id_it << "\n";
		id_it++;
	}
	output.close();
	statistics_out.close();
	

	close_can();

    return 0;
}
