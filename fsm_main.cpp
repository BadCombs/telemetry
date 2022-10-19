#include <iostream>

#include "fsm.h"

int main() {
	fsm f1;
	const char * messages[] = {
		"Ciao",						// No 
		"0A1#1234DG",				// OK
		"#12",						// No
		"30F",						// No
		"0A0#66FF",					// Stop
		"3#1234AFB1",				// OK
		"0A0#6601",					// Start
		"3#A234AFB1",				// OK
		"123#123456789"				// No	
	};
	int lens[] = {4, 10, 3, 3, 8, 10, 8, 10, 13};

	// Flag
	bool w, s, e;
	
	for (int i=0; i<9; i++) {
		std::cout << messages[i] << std::endl;
	}
	std::cout << std::endl;

	for (int i=0; i<9; i++) {
		f1.parse_entry(messages[i], lens[i], w, s, e);

		if (s) {
			std::cout << "New session started." << std::endl;
		}
		else if (e) {
			std::cout << "Current session closed." << std::endl;
		}
		else if (w) {
			std::cout << messages[i] << std::endl;
		}
	}

	return 0;
}
