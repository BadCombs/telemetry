#include "id_info.h"


// Constructors / Destructors
id_info::id_info(uint16_t _id): id(_id) {};
id_info::id_info(const id_info& source): 
	id(source.id), timestamps(source.timestamps) {};
id_info::~id_info() {
	id = 0x1000;		// ID does never exceed 0x0FFF because it is 
						// a 12 bit value
	timestamps.clear();
}

// Getter
uint16_t id_info::get_id() {return id;}
double id_info::get_mean() {
	double res = 0;
	for (time_t t: timestamps) {
		res += (double)t / (timestamps.size());
	}
	return res;
}

// Other functions
void id_info::add(time_t t) {
	timestamps.push_back(t);
}
