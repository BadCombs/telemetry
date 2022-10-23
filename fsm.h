#ifndef FSM_H
#define FSM_H

#include "message.h"

enum __state__ {Idle, Run};

class fsm {
	public:
		fsm();
		fsm(const fsm&);
		~fsm();
		
		// Return message id
		uint16_t parse_entry(const char *, int, bool&, 
							bool &, bool &);

	private:
		__state__ state;
		
		static char start1_s[];
		static char start2_s[];
		static char stop_s[];
		
		static message START_1;
		static message START_2;
		static message STOP;
};

#endif
