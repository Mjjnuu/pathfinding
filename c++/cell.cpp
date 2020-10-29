#include "cell.h"
#include <cmath>

cell::cell(int x, int y){
	coordinates[0] = x;
	coordinates[1] = y;
}

cell::cell(int x, int y, double dist){
	coordinates[0] = x;
	coordinates[1] = y;
	distance = dist;
}

cell::cell(int new_coordinates[]){
	coordinates[0] = new_coordinates[0];
	coordinates[1] = new_coordinates[1];
}

cell::cell(int new_coordinates[], double dist){
	coordinates[0] = new_coordinates[0];
	coordinates[1] = new_coordinates[1];
	distance = dist;
}

int cell::get_x(){
	return coordinates[0];
}

int cell::get_y(){
	return coordinates[1];
}

void cell::get_coordinates(int array[]){
	array = coordinates;
}

void cell::get_predecessor(int array[]){
	array = predecessor;
}

double cell::get_heuristics(int target_coordinates[]){
	return std::abs(coordinates[0] - target_coordinates[0]) + 
		   std::abs(coordinates[1] - target_coordinates[1]);
}

double cell::get_distance(){
	return distance;
}


bool cell::operator < (const cell& target){
	return distance < target.distance;
}

bool cell::operator > (const cell& target){
	return distance > target.distance;
}





