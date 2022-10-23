#ifndef FSM_H
#define FSM_H

#include "message.h"

enum __state__ {Idle, Run};

/**
 * @brief Simulate a Finite State Machine. Two states: Idle and Run.
 * 
 */
class fsm {
	public:
		/**
		 * @brief Construct a new fsm object.
		 */
		fsm();

		/**
		 * @brief Construct a new fsm object from another 
		 * already existing.
		 */
		fsm(const fsm&);
		/**
		 * @brief Destroy the fsm object.
		 */
		~fsm();
		
		/**
		 * @brief  	Receive messages, parse them depending on machine state 
		 * 			and set flags.
		 *
		 * @param entry is the message to parse.
		 *
		 * @param len is the length of entry.
		 *
		 * @param write:	true if Run and valid entry.
		 * 					false if Idle or entry not valid.
		 *
		 * @param start: 	true if Idle and entry is START message.
		 * 					false if any other conditions
		 * 					
		 * @param end:		true if Run and entry is STOP message.
		 * 					false if any other conditions.
		 * 
		 * @return uint16_t entry ID.
		 */
		uint16_t parse_entry(const char * entry, int len, 
							bool& write, 
							bool & start, 
							bool & end);

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
