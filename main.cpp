#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <set>
#include <iterator>
#include <csignal>
#include <sys/stat.h>
#include <sys/types.h>

#include "fsm.h"
#include "id_info.h"


extern "C"{
    #include "fake_receiver.h"
}

// Static 
static int session_count;
static std::set<id_info> * id_s;
static id_info * tmp_id_info;
static std::fstream output;
static std::fstream statistics_out;

void close_streams() {
	// Write on statistics file
		statistics_out << "ID,number_of_messages,mean_time\n";
		std::set<id_info>::iterator id_it = id_s->begin();
		while (id_it != id_s->end()) {
			statistics_out << *id_it << "\n";
			id_it++;
		}
		output.close();
		statistics_out.close();
		id_s->clear();
}

int main(void){
    std::cout << "Welcome to Project 2" << std::endl;

	fsm machine;
	int len;
	char buffer[MAX_CAN_MESSAGE_SIZE+1]; 	// 1 for \0 to avoid memory waste
											// while printing message
	int sub_session = 1;

	// Open session_count.txt to check last session
	std::fstream input;
	try {
		input.open("session_count.txt", std::fstream::in);
		input >> session_count;
		input.close();
		session_count++;
	}
	catch (int e) {
		session_count = 1;
	}

	// Create a new directory to put files
	int dir_created = mkdir(("session" + std::to_string(session_count)).c_str(), S_IRUSR | S_IWUSR | S_IXUSR);
	if (dir_created < 0) {
		std::cerr << "Unable to create a new directory." << std::endl;
		exit(0);
	}

	// Flags written by fsm
	bool write, start, end;
	
	// List of id_info for statistics
	id_s = new std::set<id_info>();
	std::set<id_info>::iterator id_it;
	uint16_t tmp_id;
	tmp_id_info = new id_info(0x1000);
	
	// Time start
	std::chrono::system_clock::time_point tp_system;
	std::chrono::steady_clock::time_point tp_new_session, tp_steady; 
	std::chrono::duration<double, std::milli> time_span;
	uint64_t timestamp, ms_since_new_session;

	tp_new_session = std::chrono::steady_clock::now();
	
	// Handle interrupt signals
	auto exit_fun = []
	(int i) {
		close_streams();

		close_can();
		delete id_s;
		delete tmp_id_info;

		output.open("session_count.txt", std::fstream::out);
		output << session_count << std::endl;
		output.close();
		exit(0);
	};
	std::signal(SIGINT, exit_fun);
	std::signal(SIGTERM, exit_fun);
	std::signal(SIGTSTP, exit_fun);


	// Main loop

	open_can("candump.log");

	while ((len = can_receive(buffer)) > 0) {
		tmp_id = machine.parse_entry(buffer, len, 
									write, start, end);
		
		buffer[len] = '\0';

		// Calculate time
		tp_system = std::chrono::system_clock::now();
		tp_steady = std::chrono::steady_clock::now();
		time_span = tp_steady - tp_new_session;
		timestamp = 
			(uint64_t)(std::chrono::duration_cast<std::chrono::seconds>(
					tp_system.time_since_epoch()
				).count()
			);
		ms_since_new_session = (uint64_t)time_span.count();

		if (start) {
			// Open new session file
			output.open(
				"session" + std::to_string(session_count) + "/"
				+ "session" + std::to_string(session_count) + "_"
				+ std::to_string(sub_session) + ".txt", 
				std::fstream::out
			);
			
			// Open new csv file
			statistics_out.open(
				"session" + std::to_string(session_count) + "/"
				+ "statistics" + std::to_string(session_count) + "_"
				+ std::to_string(sub_session) + ".csv",
				std::fstream::out
			);
		}
		else if (end) {
			close_streams();

			sub_session++;

			// New Idle, new session
			tp_new_session = std::chrono::steady_clock::now();
		}
		else if (write) {
			// Write on file
			/*std::cout << "(" << timestamp
					<< ") " << buffer << std::endl;*/

			output << "(" << timestamp
					<< ") " << buffer << std::endl;
			
			// Update statistics
			id_it = id_s->find(tmp_id);
			// If elem not found
			if (id_it == id_s->end()) {
				tmp_id_info->reset();
				tmp_id_info->set_id(tmp_id);
				tmp_id_info->add(ms_since_new_session);
				id_s->insert(*tmp_id_info);
			}
			else {
				id_it->add(ms_since_new_session);
			}
		}
	}

	close_streams();
	close_can();
	delete id_s;
	delete tmp_id_info;

	output.open("session_count.txt", std::fstream::out);
	output << session_count << std::endl;
	output.close();

    return 0;
}
