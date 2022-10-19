#ifndef FSM_H
#define FSM_H

#include "message.h"

enum __state__ {Idle, Run};

class fsm {
	public:
		// Constants
		static const message START_1;
		static const message START_2;
		static const message STOP;
		
		// Static methods
		static void init();
		
		fsm();
		fsm(const fsm&);
		~fsm();
		
		// Funcitons
		void parseEntry(char *, bool, bool, bool);
		

	private:
		__state__ state;
};

#endif
