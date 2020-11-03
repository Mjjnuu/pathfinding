#include "cell.h"
#include <cmath>

cell::cell(){}

cell::cell(int y, int x){
	coordinates[0] = y;
	coordinates[1] = x;
}

cell::cell(int y, int x, double dist){
	coordinates[0] = y;
	coordinates[1] = x;
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
	return coordinates[1];
}

int cell::get_y(){
	return coordinates[0];
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

bool cell::operator == (const cell& target){
	return(coordinates[0] == target.coordinates[0] && coordinates[1] == target.coordinates[1]);
}





