#include "fsm.h"

// Constructor
fsm::fsm(): state(Idle) {}

// Copy constructor
fsm::fsm(const fsm& source): state(source.state) {}

// Destructor
fsm::~fsm() {state = Idle;}
