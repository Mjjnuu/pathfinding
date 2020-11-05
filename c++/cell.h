#pragma once
#include <iostream>


class cell{

private:
	int coordinates[2];
	
	int predecessor[2] = {-1, -1};
	
	double distance;

public:
	cell();
	cell(int x, int y);
	cell(int x, int y, double dist);
	cell(int new_coordinates[]);
	cell(int new_coordinates[], double dist);
	
	int get_x();
	int get_y();
	
	void get_coordinates(int array[]);
	void get_predecessor(int array[]);
	
	int get_pre_i();
	int get_pre_j();
	
	double get_heuristics(int target_i, int target_j);
	
	double get_distance();
	
	void set_distance(double dist);
	
	void set_coordinates(int new_coordinates[]);
	void set_predecessor(int i, int j);
	
	bool operator < (const cell& target);
	bool operator > (const cell& target);
	bool operator == (const cell& target);
	
	void print(){
		std::cout << '[' << coordinates[0] << " , " << coordinates[1] << "] , " << distance;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const cell& c){
		os << '[' << c.coordinates[0] << ' ' << c.coordinates[1] << ' ' << c.distance << ']';
		return os;
	}

};
