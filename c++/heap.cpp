#include <iostream>
#include <vector>
#include <chrono>

template <class T>
class heap{
private:
	std::vector<T> heap_vector;
	int size;
	int length;

public:
	heap(){
		size = 0;
		length = 0;
	}	

	
	int get_size(){
		return size;
	}
	
	std::vector<T>* get_heap_vector(){
		return &heap_vector;
	}
	
	static int get_parent(int index){
		return (index - 1) / 2;
	}
	
	static int get_left(int index){
		return 2 * index + 1;
	}
	
	static int get_right(int index){
		return 2 * index + 2;
	}
	
	T* get_min(){
		return &heap_vector[0];
	}
	
	
	void maintain_min_heap(int index){
		int left = get_left(index);
		int right = get_right(index);
		
		int smallest = index;
		
		if(left <= size - 1 && heap_vector[left] < heap_vector[index]){
			// Store the index of the smaller element
			smallest = left;
		}
		if(right <= size - 1 && heap_vector[right] < heap_vector[smallest]){
			// Store the index of the smallest one of the three elements, the element at index
			// and it's two children
			smallest = right;
		}
		
		// If the element an index is not the smallest, the heap condition is not satisfied.
		// Swap the element at index with the smallest element and call maintain_min_heap recursively
		if(smallest != index){
			T temp = heap_vector[index];
			heap_vector[index] = heap_vector[smallest];
			heap_vector[smallest] = temp;

			maintain_min_heap(smallest);
		}
		
	}
	
	void decrease_priority(int index, T &key){
		if(key > heap_vector[index]){
			std::cout << "Not a smaller key, insertion unsuccesfull." << std::endl;
		}
		else{
			heap_vector[index] = key;
			
			// While the heap condition is not satisfied move the key closer to root
			while(index > 0 && heap_vector[index] < heap_vector[get_parent(index)]){
				// The parent is bigger, so swap it with this key
				T temp = heap_vector[index];
				heap_vector[index] = heap_vector[get_parent(index)];
				heap_vector[get_parent(index)] = temp;
				
				// Now it must be checked whether the heap condition is true for the parent, save
				// the index for the next iteration of the loop.
				index = get_parent(index);
			}
		}
	}
	
	void add(T key){
		// Increase the size of the heap by one
		size += 1;
		
		// If there is no room for a new element in the heap_vector push the key in
		if(size > heap_vector.size()){
			heap_vector.push_back(key);
		}
		else{
			heap_vector[size - 1] = key; // This may not be necessary, since decrease_priority
			// should set a new key
		}
		decrease_priority(size - 1, key);
	}
	
	
	T remove_min(){
		
		T minimum;
		
		if(size < 1){
			std::cout << "No elements on the heap" << std::endl;
		}
		else{
			minimum = heap_vector[0];
			
			// Swap the root element with the last 
			heap_vector[0] = heap_vector[size - 1];
			
			// Decrease the size
			size -= 1;
			
			maintain_min_heap(0);
		}
		
		return minimum;
	}
	
	void print_heap(){
		for(int i = 0; i < size; i++){
			std::cout << heap_vector[i] << ' ';
		}
		std::cout << std::endl;
	}
};



// Fischer-Yates algorithm for permuting an array
void FY_suffle(int array[], int length){
	for(int i = length - 1; i>0; i--){
		//0 <= random_index <= i
		int random_index = rand() % (i+1);
		int temp = array[random_index];
		array[random_index] = array[i];
		array[i] = temp;
	}
}




void print_array(int array[], int length){
	std::cout << std::endl;
	for(int i=0; i<length; i++){
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}



int main(int argc, char *argv[]){

	heap<int> kasa;
	kasa.add(6);
	int kuusi = kasa.remove_min();
	kasa.print_heap();
	kasa.add(9);
	kasa.print_heap();
	kasa.add(8);
	kasa.print_heap();
	kasa.add(3);
	kasa.print_heap();
	kasa.add(2);
	kasa.print_heap();
	kasa.add(7);
	kasa.print_heap();
	kasa.add(5);
	kasa.add(1);
	kasa.add(4);
	
	
	kasa.print_heap();
	kasa.maintain_min_heap(0);
	
	kasa.print_heap();
	//std::cout << *(kasa.get_min()) << std::endl;
	
	
	std::cout << kasa.get_size() << std::endl;
	
	int size = kasa.get_size();
	for(int i = 0; i < size; i++){
		//kasa.print_heap();
		std::cout << "i = " << i << " : ";
		//std::cout << kasa.get_size() << std::endl;
		std::cout << kasa.remove_min() << std::endl;
	}
	
	std::cout << "Variable kuusi contains: " << kuusi << std::endl;
	
	
	int array_size = 1000;
	int array[array_size];
	
	auto start = std::chrono::high_resolution_clock::now();//////////////
	
	for(int i=0;i<1000;i++){
		heap<int> Heap;
		
		int array[array_size];
		for(int j=0; j<array_size; j++){
			array[j] = j;
		}
		
		FY_suffle(array, array_size);
		
		/*
		for(int i=0; i<array_size; i++){
			std::cout << array[i] << ' ';
		}
		std::cout << std::endl;
		*/
		
		//merge_sort(array, 0, size-1);
		for(int i=0; i < array_size; i++){
			Heap.add(array[i]);
		}
		
		/*
		for(int i = 0; i< array_size; i++){
			std::cout << Heap.remove_min() << ' ';
		}
		std::cout << std::endl;
		*/
		
		//std::cout << Heap.get_size() << std::endl;
		
	}
	
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);
	std::cout << "Duration: " << duration.count() << "ms" << std::endl;
	
	
}






