import random as rnd
import heapq
import time


class min_heap:
	def __init__(self):
		self.heap_vector = []
		self.length = 0
		self.size = 0
	
	def __init__(self, vector):
		self.heap_vector = vector
		self.length = len(vector)
		self.size = len(vector)
		
		for index in range(self.get_parent(self.size - 1), -1, -1):
			self.maintain_min_heap(index)
	
	def get_size(self):
		return self.size
	
	def get_heap_vector(self):
		return self.heap_vector
	
	def get_parent(self, index):
		return (index - 1) // 2
	
	def get_left(self, index):
		return 	2*index + 1
		
	def get_right(self, index):
		return 2*index + 2
	
	def get_vector(self):
		return self.heap_vector
	
	def get_min(self):
		if self.size < 1:
			print("No elements on the heap")
		else:
			return self.heap_vector[0]

	
	def remove_min(self):
		if self.size < 1:
			print("No elements on the heap")
		else:
			minimum = self.heap_vector[0]
			self.heap_vector[0] = self.heap_vector[self.size - 1]
			self.size = self.size - 1
			
			self.maintain_min_heap(0)
			
			return minimum

	
	def add(self, key):
		self.size = self.size + 1
		if self.size > len(self.heap_vector):
			self.heap_vector.append(key)
		else:
			self.heap_vector[self.size - 1] = key	
		self.decrease_priority(self.size - 1, key)
		

		
	def maintain_min_heap(self, index):
		left = self.get_left(index)
		right = self.get_right(index)
		
		if left <= self.size - 1 and self.heap_vector[left] < self.heap_vector[index]:
			smallest = left
		else:
			smallest = index
			
		if right <= self.size -1 and self.heap_vector[right] < self.heap_vector[smallest]:
			smallest = right
			
		if smallest != index:
			temp = self.heap_vector[smallest]
			self.heap_vector[smallest] = self.heap_vector[index]
			self.heap_vector[index] = temp
			self.maintain_min_heap(smallest)


	def decrease_priority(self, index, key):
		if key > self.heap_vector[index]:
			print("Not a smaller key")
		else:
			self.heap_vector[index] = key
			
			while index > 0 and self.heap_vector[index] < self.heap_vector[self.get_parent(index)]:
				temp = self.heap_vector[index]
				self.heap_vector[index] = self.heap_vector[self.get_parent(index)]
				self.heap_vector[self.get_parent(index)] = temp
				index = self.get_parent(index)

	
