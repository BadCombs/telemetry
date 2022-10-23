#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstdint>

/**
 * @brief Structure of CAN message.
 * 
 */
class message {
	/**
	 * @brief Define equality between two message objects.
	 * 
	 * @return true if parameters have the same ID, payload and are correct.
	 * @return false if parameters are not correct of have different ID or payload. 
	 */
	friend bool operator== (const message&, const message&);
	
	public:
		/**
		 * @brief Construct a new message object.
		 * 
		 * @param s is parsed and converted to a message object.
		 * 
		 * @param len is s length.
		 */
		message(const char * s, int len);
		/**
		 * @brief Construct a new message object from an already
		 * existing one.
		 */
		message(const message&);
		/**
		 * @brief Destroy the message object.
		 * 
		 */
		~message();
		
		// Getter
		/**
		 * @brief Get message ID.
		 * 
		 * @return uint16_t message ID.
		 */
		uint16_t get_id();
		/**
		 * @brief Get message payload.
		 * 
		 * @return uint64_t message payload.
		 */
		uint64_t get_payload();
		/**
		 * @brief check message validity.
		 * 
		 * @return true if message is valid.
		 * @return false if message is not valid.
		 */
		bool is_correct();
		
		/**
		 * @brief print message.
		 * 
		 */
		void print();

	private:
		uint16_t id;
		uint64_t payload;
		bool correct;
};

#endif
