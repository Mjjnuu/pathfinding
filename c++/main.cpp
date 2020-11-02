#include <SDL.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "frame.h"
#include "cell.h"

int main(int argc, char *argv[]){
	cell c(1, 2, 4.0);
	
	cell d(3,2,3.0);
	
	c.print();
	
	int array[2] = {0,0};
	
	c.get_coordinates(array);
	
	std::cout << array[0] << ' ' << array[1] << std::endl;
	
	std::cout << (c > d) << std::endl;
	
	int width = 120;
	int height = 80;
	
	char grid[height][width] = {0};
	
	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(rand() % 100 < 30){
				grid[i][j] = 1;
			}
		}
	}
	
	Grid gr(width, height);
	gr.randomize(30);
	
	Frame frame(1200, 800, gr);
	
	frame.draw_grid(gr);
	
	SDL_Event event;
	
	srand(time(NULL));
	
	int counter = 0;
	while(event.type != SDL_QUIT){
		SDL_Delay(1);
		SDL_PollEvent(&event);
		
		if(event.type == SDL_QUIT){
			std::cout << "Shutting down..." << std::endl;
		}
		
		
		frame.draw_grid(gr);
		frame.present();
		
		gr.randomize(30);
		
		std::cout << counter << std::endl;
		
		if(counter == 100){
			break;
		}
		
		counter += 1;
	}
	
}










