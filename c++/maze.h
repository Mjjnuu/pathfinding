#pragma once
#include <SDL.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <stdlib.h>
#include <stack>
#include <vector>

#include "frame.h"

class MazeCell{
private:
	int x_coordinate;
	int y_coordinate;

public:
	MazeCell(int i, int j);
	
	int i();
	
	int j();
	
	friend bool operator==(const MazeCell &M1, const MazeCell &M2){
		return M1.x_coordinate == M2.x_coordinate && M1.y_coordinate == M2.y_coordinate;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const MazeCell& M){
		os << '[' << M.y_coordinate << ' ' << M.x_coordinate << ']';
		return os;
	}
};

bool is_unvisited(Grid &grid, int i, int j);

void generate_maze(Grid &grid);

void generate_maze(Grid &grid, Frame &frame);

/*
int main(int argc, char *argv[]){

	std::stack<MazeCell> cell_stack;

	
	int grid_width = 31;
	int grid_height = 31;
	
	Grid grid(grid_width, grid_height);
	grid.randomize(100);
	Frame frame(1000, 1000, grid);
	
	frame.draw_grid(grid);
	
	SDL_Event event;
	
	srand(time(NULL));
	int random_i = (rand() % (grid_height / 2)) * 2 + 1;
	int random_j = (rand() % (grid_width / 2)) * 2 + 1;
	 
	MazeCell initial_cell(random_i, random_j);
	cell_stack.push(initial_cell);
	
	grid.set_cell(initial_cell.i(), initial_cell.j(), 0);
	frame.draw_cell(initial_cell.i(), initial_cell.j(), 255,255,255,255);
	
	while(event.type != SDL_QUIT && cell_stack.size() > 0){
		SDL_Delay(1);
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT){
			std::cout << "Shutting down..." << std::endl;
			return 0;
		}
		
		MazeCell current_cell = cell_stack.top();
		cell_stack.pop();
		
		int i = current_cell.i();
		int j = current_cell.j();
	
		// Make a vector containing all the valid and non-visited neighbors of cell i,j
		std::vector<int> unvisited_neighbors_i;
		std::vector<int> unvisited_neighbors_j;
		
		if(is_unvisited(grid, i-2,j)){
			unvisited_neighbors_i.push_back(i-2);
			unvisited_neighbors_j.push_back(j);
		}
		if(is_unvisited(grid, i+2,j)){
			unvisited_neighbors_i.push_back(i+2);
			unvisited_neighbors_j.push_back(j);
		}
		if(is_unvisited(grid, i,j-2)){
			unvisited_neighbors_i.push_back(i);
			unvisited_neighbors_j.push_back(j-2);
		}
		if(is_unvisited(grid, i,j+2)){
			unvisited_neighbors_i.push_back(i);
			unvisited_neighbors_j.push_back(j+2);
		}
		
		if(unvisited_neighbors_i.size() != 0){
			cell_stack.push(current_cell);
			// Choose one of the unvisited neighbors
			int index = rand() % unvisited_neighbors_i.size();
			int chosen_i = unvisited_neighbors_i[index];
			int chosen_j = unvisited_neighbors_j[index];
			
			// Remove the wall between the chosen cell and current cell
			if(chosen_i < i){
				grid.set_cell(i-1,j,0);
				frame.draw_cell(i-1,j,255,255,255,255);
			}
			if(chosen_i > i){
				grid.set_cell(i+1,j,0);
				frame.draw_cell(i+1,j,255,255,255,255);
			}
			if(chosen_j < j){
				grid.set_cell(i,j-1,0);
				frame.draw_cell(i,j-1,255,255,255,255);
			}
			if(chosen_j > j){
				grid.set_cell(i,j+1,0);
				frame.draw_cell(i,j+1,255,255,255,255);
			}
			
			// Mark the chosen cell as visited
			grid.set_cell(chosen_i, chosen_j, 0);
			frame.draw_cell(chosen_i, chosen_j, 255,255,255,255);
			// Push the chosen cell onto the stack
			MazeCell chosen(chosen_i, chosen_j);
			cell_stack.push(chosen);
		}

		frame.present();
	}
	
	while(event.type != SDL_QUIT){
			SDL_Delay(1);
			SDL_PollEvent(&event);
			if(event.type == SDL_QUIT){
				std::cout << "Shutting down..." << std::endl;
			}
			
			frame.present();
		}
	
	return 0;
}

*/
