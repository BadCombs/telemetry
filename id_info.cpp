#include "id_info.h"

#include <iomanip>

// Constructors / Destructors
id_info::id_info(uint16_t _id): id(_id) {
	timestamps = new std::list<uint64_t>();
};
id_info::id_info(const id_info& source): 
	id(source.id) {
	
	timestamps = new std::list<uint64_t>(*(source.timestamps));
};
id_info::~id_info() {
	id = 0x1000;		// ID does never exceed 0x0FFF because it is 
						// a 12 bit value
	timestamps->clear();
	delete timestamps;
}

// Getter
uint16_t id_info::get_id() const {return id;}
double id_info::get_mean() const {
	double res = 0;
	uint64_t last_t = timestamps->front();
	for (uint64_t t: *timestamps) {
		res += (double)(t-last_t) / (timestamps->size());
		last_t = t;
	}
	return res;
}

// Setter
void id_info::set_id(uint16_t _id) {
	id = _id;
}

// Other functions
void id_info::add(uint64_t t) const {
	timestamps->push_back(t);
}
void id_info::reset() {
	id = 0x1000;
	timestamps->clear();
}

// Overloading operator
bool id_info::operator== (uint16_t i) const {
	return (id == i);
}	
bool id_info::operator< (const id_info& o) const {
	return (id < o.id);
}

// CSV standard
std::ostream& operator<< (std::ostream& out, const id_info& s) {
	out << std::uppercase << std::hex << std::setfill('0') << std::setw(3)
		<< s.get_id() << "," << std::dec << s.timestamps->size() << "," << s.get_mean();
	return out;
}
