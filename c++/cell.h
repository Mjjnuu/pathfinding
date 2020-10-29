#pragma once
#include <iostream>


class cell{

private:
	int coordinates[2];
	
	int predecessor[2];
	
	double distance;

public:
	cell(int x, int y);
	cell(int x, int y, double dist);
	cell(int new_coordinates[]);
	cell(int new_coordinates[], double dist);
	
	int get_x();
	int get_y();
	
	void get_coordinates(int array[]);
	void get_predecessor(int array[]);
	
	double get_heuristics(int target_coordinates[]);
	
	double get_distance();
	
	void set_distance(double dist);
	
	void set_coordinates(int new_coordinates[]);
	
	bool operator < (const cell& target);
	bool operator > (const cell& target);
	
	void print(){
		std::cout << '[' << coordinates[0] << " , " << coordinates[1] << "] , " << distance << std::endl;
	}

};
