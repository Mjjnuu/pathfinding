#include <SDL.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "frame.h"
#include "cell.h"
#include "heap.cpp"


int main(int argc, char *argv[]){

	int width = 120;
	int height = 80;
	
	Grid gr(width, height);
	gr.randomize(30);
	
	int start_coordinates[2] = {5, 10};
	cell start_cell = cell(start_coordinates[0], start_coordinates[1], 0.0);
	
	int target_coordinates[2] = {height - 10, width - 5};
	
	heap<cell> cell_heap;
	cell_heap.add(start_cell);
	
	Frame frame(1200, 800, gr);
	
	frame.draw_grid(gr);
	
	frame.draw_cell(target_coordinates[0], target_coordinates[1], 0,0,255,0);
	
	SDL_Event event;
	
	srand(time(NULL));
	
	int counter = 0;
	int heap_number = 1;
	int i = start_coordinates[0];
	int j = start_coordinates[1];
	
	while(event.type != SDL_QUIT){ // && cell_heap.get_size() > 0){
		SDL_Delay(1);
		SDL_PollEvent(&event);
		
		if(event.type == SDL_QUIT){
			std::cout << "Shutting down..." << std::endl;
		}
		
		// Business-logic of the dijkstra-algorithm
		cell* current_cell = cell_heap.get_min();
		cell_heap.remove_min();
		heap_number -= 1;
		double current_dist = current_cell->get_distance();
		
		
		i = current_cell->get_y();
		j = current_cell->get_x();
		
		if(i == target_coordinates[0] && j == target_coordinates[1]){
			break;
		}
		
		std::cout << i << ' ' << j << std::endl;
		
		// The current cell has been checked, so change the value to 3
		gr.set_cell(i, j, 3);
		frame.draw_cell(i, j, 255,0,0,0);
		
		if(gr.is_valid(i-1, j)){
			// Check if the cell at i-1, j is in the cell_heap, add it if not
			if(gr.get(i-1,j) != 2){
				cell new_cell(i-1, j, current_dist + 1);
				cell_heap.add(new_cell);
				heap_number += 1;
				gr.set_cell(i-1,j,2);
				frame.draw_cell(i-1, j, 0,255,0,0);
			}	
		}
		if(gr.is_valid(i+1, j)){
			// Check if the cell at i-1, j is in the cell_heap, add it if not
			if(gr.get(i+1,j) != 2){
				cell new_cell(i+1, j, current_dist + 1);
				cell_heap.add(new_cell);
				heap_number += 1;
				gr.set_cell(i+1,j,2);
				frame.draw_cell(i+1, j, 0,255,0,0);
			}	
		}
		if(gr.is_valid(i, j-1)){
			// Check if the cell at i-1, j is in the cell_heap, add it if not
			if(gr.get(i,j-1) != 2){
				cell new_cell(i, j-1, current_dist + 1);
				cell_heap.add(new_cell);
				heap_number += 1;
				gr.set_cell(i,j-1,2);
				frame.draw_cell(i, j-1, 0,255,0,0);
			}	
		}
		if(gr.is_valid(i, j+1)){
			// Check if the cell at i-1, j is in the cell_heap, add it if not
			if(gr.get(i,j+1) != 2){
				cell new_cell(i, j+1, current_dist + 1);
				cell_heap.add(new_cell);
				heap_number += 1;
				gr.set_cell(i,j+1,2);
				frame.draw_cell(i, j+1, 0,255,0,0);
			}	
		}
		
		//std::cout << cell_heap.get_size() - heap_number << std::endl;
		
		//frame.draw_grid(gr);
		frame.present();
		
		//std::cout << counter << std::endl;
		
		if(counter == 100){
			//break;
		}
		
		counter += 1;
	}
	
}










