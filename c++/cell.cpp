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

int cell::get_pre_i(){
	return predecessor[0];
}
	
int cell::get_pre_j(){
	return predecessor[1];
}

double cell::get_heuristics(int target_i, int target_j){
	return std::abs(coordinates[0] - target_i) + 
		   std::abs(coordinates[1] - target_j);
}

double cell::get_distance(){
	return distance;
}

void cell::set_distance(double dist){
	distance = dist;
}

void cell::set_predecessor(int i, int j){
	predecessor[0] = i;
	predecessor[1] = j;
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





