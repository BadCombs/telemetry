#ifndef ID_INFO_H
#define ID_INFO_H

#include <ctime>
#include <list>
#include <cstdint>

class id_info {
	public:
		id_info(uint16_t);
		id_info(const id_info&);
		~id_info();

		// Getter
		uint16_t get_id();
		double get_mean();
		
		void add(time_t);

	private:
		uint16_t id;
		std::list<time_t> timestamps;
};

#endif
