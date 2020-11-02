#include <iostream>
#include <SDL.h>
#include <time.h>
#include <stdlib.h>
#include "frame.h"



Grid::Grid(int width, int height){
		
	grid_width = width;
	grid_height = height;
}
	
Grid::~Grid(){
}
	
int Grid::get_width(){
	return grid_width;
}
	
int Grid::get_height(){
	return grid_height;
}



Frame::Frame(int max_width, int max_height, Grid grid){
	grid_width = grid.get_width();
	grid_height = grid.get_height();
	
	int cell_width = max_width / grid_width;
	int cell_height = max_height / grid_height;
	
	// The smallest one of these is set as the size of cells
	if(cell_width < cell_height){
		cell_size = cell_width;
	}
	else{
		cell_size = cell_height;
	}
	
	frame_width = cell_size * grid_width;
	frame_height = cell_size * grid_height;
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(frame_width, frame_height, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 10, 15, 30, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}
	
Frame::~Frame(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
	
void Frame::draw_cell(int i, int j, int r, int g, int b, int a){
	int x = cell_size * i;
	int y = cell_size * j;
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	for(int delta_x = 0; delta_x < cell_size; delta_x ++){
		for(int delta_y = 0; delta_y < cell_size; delta_y ++){
			SDL_RenderDrawPoint(renderer, x + delta_x, y + delta_y);
		}
	}
	SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]){
	Grid grid(190,100);
	
	std::cout << "Done" << std::endl;
	
	Frame my_frame(800, 400, grid);
	std::cout << "Done" << std::endl;
	
	my_frame.draw_cell(2,3, 0, 255, 0, 0);
	std::cout << "Done" << std::endl;
	
	SDL_Event event;
	
	srand(time(NULL));
	
	while(event.type != SDL_QUIT){
		SDL_Delay(1);
		SDL_PollEvent(&event);
		
		if(event.type == SDL_QUIT){
			std::cout << "Shutting down..." << std::endl;
		}
		
		my_frame.draw_cell(12, 15, 255,0,0,0);
		//my_frame.draw_cell(gr.get_y(), gr.get_x(), 0, 255, 0,0);
		
	}
}





