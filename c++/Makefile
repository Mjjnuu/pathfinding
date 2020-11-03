cell.o: cell.cpp cell.h
	g++ -c cell.cpp

heap.o: heap.cpp 
	g++ -c heap.cpp

frame.o: frame.cpp frame.h
	g++ -c frame.cpp `sdl2-config --cflags --libs`


main.o: main.cpp
	g++ -c main.cpp `sdl2-config --cflags --libs`


main: main.o cell.o heap.o frame.o
	g++ -o main main.o cell.o heap.o frame.o `sdl2-config --cflags --libs`
	rm *.o


