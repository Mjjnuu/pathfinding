#include <iostream>
#include "cell.h"

int main(int argc, char *argv[]){
	cell c(1, 2, 4.0);
	
	cell d(3,2,3.0);
	
	c.print();
	
	int array[2] = {0,0};
	
	c.get_coordinates(array);
	
	std::cout << array[0] << ' ' << array[1] << std::endl;
	
	std::cout << (c > d) << std::endl;
}
