cell.o: cell.cpp cell.h
	g++ -O3 -c cell.cpp

heap.o: heap.cpp 
	g++ -O3 -c heap.cpp

frame.o: frame.cpp frame.h
	g++ -O3 -c frame.cpp `sdl2-config --cflags --libs`

maze.o: maze.cpp maze.h
	g++ -O3 -c maze.cpp `sdl2-config --cflags --libs`

main.o: main.cpp
	g++ -O3 -c main.cpp `sdl2-config --cflags --libs`


main: main.o cell.o heap.o frame.o maze.o
	g++ -O3 -o main main.o cell.o heap.o frame.o maze.o `sdl2-config --cflags --libs`
	


