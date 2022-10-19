#ifndef FSM_H
#define FSM_h

enum __state__ {Idle, Run};

class fsm {
	public:
		fsm();
		fsm(const fsm&);
		~fsm();

		// Funcitons
		void parseString(char * s);

	private:
		__state__ state;
};

#endif
