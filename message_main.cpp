#include <iostream>
#include "message.h"

int main() {
		
	//char s1[] = {'0', 'A', '0', '#', '6', '6', '0', '1'};
	char s1[] = "FF1#00";
	char s2[] = {'0', 'A', '0', '#', '6', '6', '0', '1'};
	message m1(s1, 6);
	message m2(s2, 8);
	
	m1.print();
	m2.print();

	std::cout << (m1 == m2) << std::endl;

	return 0;
}
