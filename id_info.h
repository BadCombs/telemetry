#ifndef ID_INFO_H
#define ID_INFO_H

#include <list>
#include <cstdint>
#include <iostream>

class id_info {
	friend std::ostream& operator<< (std::ostream&, const id_info&);

	public:
		id_info(uint16_t);
		id_info(const id_info&);
		~id_info();

		// Getter
		uint16_t get_id() const;
		double get_mean() const;
		
		// Setter
		void set_id(uint16_t);

		void add(uint64_t) const;
		void reset();

		
		bool operator== (uint16_t) const;
		bool operator< (const id_info&) const;

	private:
		uint16_t id;
		std::list<uint64_t> * timestamps;
};
#endif
