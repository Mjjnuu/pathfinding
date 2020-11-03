#pragma once
#include <iostream>
#include <SDL.h>
#include <time.h>
#include <stdlib.h>

class Grid{
private:
	int grid_width;
	int grid_height;
	
	char* grid;

	
public:
	Grid(int width, int height);
	
	~Grid();
	
	int get_width();
	
	int get_height();
	
	void randomize(int percentage);
	
	void set_cell(int i, int j, char value);
	
	char get(int i, int j);
	
	bool is_valid(int i, int j);


};


class Frame{
private:
	int frame_width;
	int frame_height;
	int grid_width;
	int grid_height;
	int cell_size;
	
	SDL_Renderer *renderer = NULL;
	SDL_Window *window = NULL;
	
public:
	Frame(int max_width, int max_height, Grid grid);
	
	~Frame();
	
	void draw_cell(int i, int j, int r, int g, int b, int a);
	
	void draw_grid(Grid &grid);
	
	void present();
};




