#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstdint>

class message {
	friend bool operator== (const message&, const message&);
	
	public:
		message(char *, int);
		message(const message&);
		~message();
		
		// Getter
		uint16_t get_id();
		uint32_t get_payload();
		bool is_correct();
		
		void print();

	private:
		uint16_t id;
		uint32_t payload;
		bool correct;
};

#endif
