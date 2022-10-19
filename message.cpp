#include "message.h"

#include <cmath>


// util functions
bool is_hex_ciph(char c) {
	return (('0' <= c && c <= '9') || ('A' <= c && c <= 'F'));
}

unsigned int s_to_hex(char * s, int len) {
	unsigned int res = 0;
	uint8_t tmp;
	
	for (int k=len-1; k>=0; k--) {
		if ('0' <= s[k] && s[k] <= '9') {
			tmp = s[k] - '0';
		}
		else if ('A' <= s[k] && s[k] <= 'F') {
			tmp = s[k] - 'A';
		}

		res += tmp * std::pow(16, len-k-1);
	}

	return res;
}

// message member functions

// Constructor
message::message(char * s, int len) {
	bool go_on = true;
	char id_s[3]; // At most 12 bits, hence 3 hex ciphers. 
	char payload_s[16]; // At most 8 bytes, hence 16 hex ciphers.
	
	int i, j = 0;

	// Copy id
	while (go_on && i<len && i<3 && is_hex_ciph(s[i])) {
		id_s[i] = s[i]; 
		i++;
	}
	// Check "#" character
	if (s[i] != '#' || i < 1) { // Id should have at least 1 char
		go_on = false;
	}
	else {
		i++;
		j = i;
		// Check if payload field occupies an even number of char
		if ((len-i)%2 != 0) {
			go_on = false;
		}
	}

	// Copy payload
	while (go_on && j<len &&(j-i)<8 && is_hex_ciph(s[j])) {
		payload_s[j] = s[j];
		j++;
	}
	// Check 
	if (j<len) {
		go_on = false;
	}
	
	// Parse id and payload to int
	if ((correct = go_on)) {
		id = (uint16_t) s_to_hex(id_s, i-1);
		payload = (uint32_t) s_to_hex(payload_s, j-i);
	}
	else {
		id = payload = 0;
	}
}

// Copy constructor
message::message(const message& source) {
	id = source.id;
	payload = source.payload;
	correct = source.correct;
}

// Desctructor
message::~message() {
	id = payload = 0;
	correct = false;
}

// Getter
uint16_t message::get_id() {return id;}
uint32_t message::get_payload() {return payload;}
bool message::is_correct() {return correct;}

// Friend functions
friend bool operator== (const message& m1, const message& m2) {
	return (
		m1.id == m2.id &&
		m1.payload == m2.payload &&
		m1.correct == m2.correct
	)
}
