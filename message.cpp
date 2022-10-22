#include "message.h"

#include <iostream>


// util functions
bool is_hex_ciph(char c) {
	return (('0' <= c && c <= '9') || ('A' <= c && c <= 'F'));
}

uint64_t uint_pow(uint32_t b, uint32_t e) {
	uint64_t res = 1;
	for (uint32_t i=1; i<=e; i++) {
		res *= (uint64_t)b;
	}
	return res;
}

uint64_t s_to_hex(char * s, int len) {
	uint64_t res = 0;
	uint8_t tmp;
	
	for (int k=len-1; k>=0; k--) {
		if ('0' <= s[k] && s[k] <= '9') {
			tmp = s[k] - '0';
		}
		else if ('A' <= s[k] && s[k] <= 'F') {
			tmp = s[k] - 'A' + 10;
		}

		res += ((uint64_t) tmp) * uint_pow(16, len-k-1);
	}

	return res;
}

// message member functions

// Constructor
message::message(const char * s, int len) {
	bool go_on = true;
	char id_s[3]; // At most 12 bits, hence 3 hex ciphers. 
	char payload_s[16]; // At most 8 bytes, hence 16 hex ciphers.
	
	int i = 0, j = 0;

	// Copy id
	while (go_on && i<len && i<3 && is_hex_ciph(s[i])) {
		id_s[i] = s[i]; 
		i++;
	}
	// Check "#" character
	if (s[i] != '#' || i < 1 || i==len) { // Id should have at least 1 char
		go_on = false;
	}
	else {
		i++;
		j = i;
		// Check if payload field occupies an even number of char
		if ((len-i) == 0 || (len-i)%2 != 0) {
			go_on = false;
		}
	}

	// Copy payload
	while (go_on && j<len && (j-i)<16 && is_hex_ciph(s[j])) {
		payload_s[j-i] = s[j];
		j++;
	}
	// Check 
	if (j<len) {
		go_on = false;
	}
	
	// Parse id and payload to int
	if ((correct = go_on)) {
		id = (uint16_t) s_to_hex(id_s, i-1);
		payload = (uint64_t) s_to_hex(payload_s, j-i);
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
uint64_t message::get_payload() {return payload;}
bool message::is_correct() {return correct;}

void message::print() {
	std::cout 	<< "Id: " << id << std::endl
				<< "Payload: " << payload << std::endl
				<< "Correct: " << correct << std::endl;
}

// Friend functions
bool operator== (const message& m1, const message& m2) {
	return (
		m1.id == m2.id &&
		m1.payload == m2.payload &&
		m1.correct && m2.correct
	);
}
