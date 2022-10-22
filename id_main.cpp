#include <iostream>
#include "id_info.h"

int main() {
	id_info tmp(0x0A0);
	
	for (time_t i=0; i<20; i++) {
		tmp.add(i);
	}
	std::cout 	<< "Id: " << tmp.get_id() << std::endl
				<< "Mean: " << tmp.get_mean() << std::endl;


	return 0;
}
