#include "fsm.h"

// Static members initialization

char fsm::start1_s[] = "0A0#6601";
char fsm::start2_s[] = "0A0#FF01";
char fsm::stop_s[] = "0A0#66FF";

message fsm::START_1(start1_s, 8);
message fsm::START_2(start2_s, 8);
message fsm::STOP(stop_s, 8);


// Constructor
fsm::fsm(): state(Idle) {}

// Copy constructor
fsm::fsm(const fsm& source): state(source.state) {}

// Destructor
fsm::~fsm() {state = Idle;}

// Set flags for caller
void fsm::parse_entry(
	const char * entry, int len,
	bool & write,
	bool & start, 
	bool & end 
) {
	message tmp(entry, len);
	if (tmp.is_correct()) {
		if (state == Idle) {
			write = false;
			
			// If receive a Run message
			if (tmp == START_1 || tmp == START_2) {
				state = Run;
				start = true;
				end = false;
			}
			else {
				start = end = false;
			}
		}
		else if (state == Run) {
			// If receive a stop message
			if (tmp == STOP) {
				state = Idle;
				write = start = false;
				end = true;
			}
			else {
				if (!(tmp == START_1 || tmp == START_2)) {
					write = true;
				}
				else {
					write = false;
				}
				start = end = false;
			}
		}
	}
	else {
		write = start = end = false;
	}
}
