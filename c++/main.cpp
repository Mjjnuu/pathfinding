#include <SDL.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include "frame.h"
#include "cell.h"
#include "heap.cpp"

#include <cmath>

void updateCell(int i, int j, cell &current_cell, heap<cell> &cell_heap, Grid &grid, Frame &frame){
	if(grid.is_valid(i,j)){
		double distance = current_cell.get_distance();
		//std::cout << "A: " << distance << std::endl;
		cell new_cell(i, j, distance + 1);
		new_cell.set_predecessor(current_cell.get_y(), current_cell.get_x());

		// If new_cell is not in the heap add it
		if(grid.get(i,j) != 2){
			cell_heap.add(new_cell);
			
			grid.set_cell(i, j, 2);
			frame.draw_cell(i, j, 0, 255, 0, 255);
		}// Otherwise update the cell in the heap
		else{
			int index = cell_heap.search(new_cell);
			
			if(distance + 1 < cell_heap.get(index)->get_distance()){
				cell_heap.decrease_priority(index, new_cell);
			}
		}
	}
}

void AupdateCell(int i, int j, int target_i, int target_j, cell& current_cell, 
				 heap<cell> &cell_heap, Grid &grid, Frame &frame){
	
				 
	if(grid.is_valid(i,j)){
		double distance = 
			current_cell.get_distance() - current_cell.get_heuristics(target_i, target_j);
		
		//std::cout << "A: " << current_cell.get_heuristics(target_i, target_j) << std::endl;
			
		cell new_cell(i, j);
		new_cell.set_predecessor(current_cell.get_y(), current_cell.get_x());

		double h_score = new_cell.get_heuristics(target_i, target_j);
		
		new_cell.set_distance(distance + h_score + 1);
		
		//std::cout << "B: " << distance << std::endl;
		// If new_cell is not in the heap add it
		if(grid.get(i,j) != 2){
			cell_heap.add(new_cell);
			grid.set_cell(i, j, 2);
			frame.draw_cell(i, j, 0, 255, 0, 0);
		}// Otherwise update the cell in the heap
		else{
			int index = cell_heap.search(new_cell);
			
			if(distance + h_score + 1 < cell_heap.get(index)->get_distance()){
				cell_heap.decrease_priority(index, new_cell);
			}
		}
	}
}

int main(int argc, char *argv[]){

	srand(time(NULL));
	
	int width = 180;
	int height = 128;
	
	Grid gr(width, height);
	gr.randomize(30);
		
	auto start = std::chrono::high_resolution_clock::now();
	
	int start_coordinates[2] = {10, 10};
	int target_coordinates[2] = {height - 10, width - 10};
	
	cell start_cell = cell(start_coordinates[0], start_coordinates[1]);
	
	double to_target = start_cell.get_heuristics(target_coordinates[0], target_coordinates[1]);
	start_cell.set_distance(to_target);
	std::cout << "Distance to target: " << to_target << std::endl;
	//start_cell.set_distance(0.0);
	
	
	heap<cell> cell_heap;
	cell_heap.add(start_cell);
	
	std::vector<cell> checked_cells;
	
	Frame frame(1440, 1024, gr);
	gr.set_cell(target_coordinates[0], target_coordinates[1], 4);
	
	frame.draw_grid(gr);
	
	frame.draw_cell(target_coordinates[0], target_coordinates[1], 0,0,255,0);
	
	SDL_Event event;
	
	int counter = 0;

	int i = start_coordinates[0];
	int j = start_coordinates[1];
	
	int target_found = 0;
	
	while( cell_heap.get_size() > 0){
		SDL_Delay(1);
		SDL_PollEvent(&event);
		
		if(event.type == SDL_QUIT){
			std::cout << "Shutting down..." << std::endl;
			break;
		}
		
		if(!target_found)
		{
		// Business-logic of the dijkstra-algorithm
		cell current_cell = *(cell_heap.get_min());
		
		i = current_cell.get_y();
		j = current_cell.get_x();
		
		checked_cells.push_back(current_cell);
		cell_heap.remove_min();
		
		if(i == target_coordinates[0] && j == target_coordinates[1]){
			//break;
			target_found = 1;
		}
		
		//std::cout << i << ' ' << j << std::endl;
		
		// The current cell has been checked, so change the value to 3
		gr.set_cell(i, j, 3);
		frame.draw_cell(i, j, 255,0,0,255);
		
		
		/*
		updateCell(i-1, j, current_cell, cell_heap, gr, frame);
		updateCell(i+1, j, current_cell, cell_heap, gr, frame);
		updateCell(i, j-1, current_cell, cell_heap, gr, frame);
		updateCell(i, j+1, current_cell, cell_heap, gr, frame);
		*/
		
		
		int target_i = target_coordinates[0];
		int target_j = target_coordinates[1];
		AupdateCell(i-1, j, target_i, target_j, current_cell, cell_heap, gr, frame);
		AupdateCell(i+1, j, target_i, target_j, current_cell, cell_heap, gr, frame);
		AupdateCell(i, j-1, target_i, target_j, current_cell, cell_heap, gr, frame);
		AupdateCell(i, j+1, target_i, target_j, current_cell, cell_heap, gr, frame);
		
		}
		else{
			// Target is found
			std::cout << "Done!" << std::endl;
			auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
			std::cout << "Duration: " << duration.count() << "ms" << std::endl;
			break;
		}
		
		//frame.draw_grid(gr);
		frame.present();
		
		//frame.draw_cell(start_coordinates[0], start_coordinates[1], 255,255,0,0);
		
		
		//std::cout << counter << std::endl;
		
		if(counter == 100){
			//break;
		}
		
		counter += 1;
	}

	int index = checked_cells.size() - 1;
	cell last_cell = checked_cells[index];
	int pre_i = last_cell.get_pre_i();
	int pre_j = last_cell.get_pre_j();
	
	if(target_found){
		int counter = 0;
		while(pre_i != -1 || pre_j != -1){
		
			//std::cout << pre_i << ' ' << pre_j << std::endl;
			frame.draw_cell(pre_i, pre_j, 0,0,255,255);

			for(int i = 0; i < checked_cells.size(); i++){
				// Store the coordinates of the i:th cell onto temp
				int temp_i = checked_cells[i].get_y();
				int temp_j = checked_cells[i].get_x();
			
				if(i != index && temp_i == pre_i && temp_j == pre_j){
					// The predecessor cell found
					index = i;
				}
			}
			pre_i = checked_cells[index].get_pre_i();
			pre_j = checked_cells[index].get_pre_j();
		}
	}
	
	
	while(event.type != SDL_QUIT){
		SDL_Delay(1);
		SDL_PollEvent(&event);
		
		frame.present();
		
		if(event.type == SDL_QUIT){
			std::cout << "Shutting down..." << std::endl;
			break;
		}
	}
	/*
	frame.draw_grid(gr);
	
	while(event.type != SDL_QUIT){
		SDL_Delay(1);
		frame.present();
	}
	*/
	
}










