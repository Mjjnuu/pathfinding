import numpy as np
import random as rnd
import time
import matplotlib.pyplot as plt
import matplotlib.colors as colors
from queue import PriorityQueue
import heap

class cell:
	"""
	def __init__(self, coordinates):
		self.coordinates = coordinates
		self.predecessor = None
		
		self.dist = 0
	"""	
	def __init__(self, coordinates, dist = None):
		self.coordinates = coordinates
		self.predecessor = None
		self.dist = dist
	
	def __lt__(self, other):
		if self.get_dist() < other.get_dist():# or other.get_dist() == None:
			return True
		else:
			return False
	
	def __gt__(self, other):
		if self.get_dist() > other.get_dist():
			return True
		else:
			return False
	
	def __eq__(self, other):
		return self.get_dist() == other.get.dist()
	
	def __le__(self, other):
		if self.get_dist() <= other.get_dist():
			return True
		else:
			return False
	
	def __ge__(self, other):
		if self.get_dist() >= other.get_dist():
			return True
		else:
			return False
	
		
		
	def get_heuristics(self, target_coordinates):
		xdiff = abs(self.coordinates[0] - target_coordinates[0]) 
		ydiff = abs(self.coordinates[1] - target_coordinates[1])
		return xdiff + ydiff 	
		
	
	def get_predecessor(self):
		return self.predecessor
	
	def get_dist(self):
		return self.dist
		
	def get_coordinates(self):
		return self.coordinates	
	
	def search_array(self, array):
		coordinates = self.coordinates #cell.get_coordinates()
		for i in range(len(array)):
			if coordinates == array[i].get_coordinates():
				return i
		return None
	
	"""
	def search_array(array, coordinates):
		for i in range(len(array)):
			if coordinates == array[i].get_coordinates():
				return i
		return None
	"""	
	
	def set_dist(self, dist):
		self.dist = dist
		
	def set_predecessor(self, coordinates):
		self.predecessor = coordinates	


"""
yksi = cell([1,1], 1)
kaksi = cell([2,2], 2)
kolme = cell([3,3], 3)
nelja = cell([4,4], 4)
viisi = cell([5,5], 5)
kuusi = cell([6,6], 6)
seitseman = cell([7,7], 7)
kahdeksan = cell([8,8], 8)
yhdeksan = cell([9,9], 9)

vector = [kuusi, kahdeksan, nelja, seitseman, yksi, kolme, kaksi, viisi]

print(cell.search_array(vector, nelja))

heap_of_cells = heap.min_heap(vector)
for i in range(8):
	cell = heap_of_cells.remove_min()
	print(cell.get_coordinates())

print(kolme < kaksi)
"""















