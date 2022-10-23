#ifndef ID_INFO_H
#define ID_INFO_H

#include <list>
#include <cstdint>
#include <iostream>

/**
 * @brief Save all timestamps associated with an ID.
 * 
 */
class id_info {
	/**
	 * @brief Insert ID, recurrences and mean of elapsed time 
	 * between timestamps in output stream.
	 * 
	 * @return std::ostream& output stream.
	 */
	friend std::ostream& operator<< (std::ostream&, const id_info&);

	public:
		/**
		 * @brief Construct a new id_info object.
		 * @param is the ID to associate to the new object.
		 */
		id_info(uint16_t _id);
		/**
		 * @brief Construct a new id_info object from another
		 * already existing.
		 */
		id_info(const id_info&);
		/**
		 * @brief Destroy the id info object.
		 * 
		 */
		~id_info();

		// Getter
		/**
		 * @brief Get the associated ID.
		 * 
		 * @return uint16_t ID.
		 */
		uint16_t get_id() const;
		/**
		 * @brief Get the mean of elapsed time between timestamps.
		 * 
		 * @return double mean.
		 */
		double get_mean() const;
		
		// Setter
		/**
		 * @brief Set a new ID.
		 * 
		 * @param _id is the new ID to associate.
		 */
		void set_id(uint16_t _id);

		/**
		 * @brief Add a new timestamp.
		 * 
		 * @param t is the timestamp to add.
		 */
		void add(uint64_t t) const;
		/**
		 * @brief Set ID to 1000 (Not used) and remove all timestamps.
		 * 
		 */
		void reset();

		/**
		 * @brief Check if the ID associated to the current 
		 * object is equal to a given ID. Used by 
		 * container classes to find an element.
		 * 
		 * @param i is the ID to compare.
		 * 
		 * @return true if object ID == i.
		 * @return false if object ID != i.
		 */
		bool operator== (uint16_t i) const;
		/**
		 * @brief Check if the ID associated to the current 
		 * object is less than a given ID. Used by 
		 * container classes to sort elements.
		 * 
		 * @param o is the id_info object to compare
		 * to the current id_object.
		 * 
		 * @return true if ID value of *this is less than 
		 * the ID value of o 
		 * @return false if ID value of o is greater or equal 
		 * than the ID value of *this
		 */
		bool operator< (const id_info& o) const;

	private:
		uint16_t id;
		std::list<uint64_t> * timestamps;
};

#endif
