import numpy as np
import random as rnd
import time
import matplotlib.pyplot as plt
import matplotlib.colors as colors
import heap
import cell as cl

width = 120
height = 80
grid = np.zeros([height,width])

for i in range(height):
	for j in range(width):
		if rnd.random() < 0.3:
			grid[i,j] = 1

"""
grid[5,3:15] = 1
grid[5:20,5] = 1
grid[10,10:25] = 1
"""
colormap = colors.ListedColormap(['#ffffff', '#000000', '#00ff00', '#ff0000', '#0000ff'])
boundaries = [-0.5, 0.5, 1.5, 2.5,3.5,4.5]
norm = colors.BoundaryNorm(boundaries=boundaries, ncolors=5)


fig = plt.figure()
plt.imshow(grid, cmap=colormap, norm=norm)
fig.show()


start_coordinates = [10,10]
start_cell = cl.cell(start_coordinates, 0)

target_coordinates = [height - height//4, width - width//5]
target = target_coordinates 

grid[target_coordinates[0], target_coordinates[1]] = 4

cell_heap = heap.min_heap([start_cell])
checked_cells = []

i=0
j=0
start = time.time()
while cell_heap.get_size() > 0:
	fig.clear()
	current_cell = cell_heap.remove_min()
	
	checked_cells.append(current_cell)
	
	#print(cell_heap.get_size())
	current_dist = current_cell.get_dist()
	[i,j] = current_cell.get_coordinates() 
	
	if [i,j] == target_coordinates:
		break
	
	# Turn this gridpoint into red
	grid[i,j] = 3
	#print("removed")
	
	heap_vector = cell_heap.get_heap_vector()
	
	neighbors = []
	
	if i-1 >= 0 and grid[i-1,j] != 3 and grid[i-1,j] != 1: 
		#new_cell = cl.cell([i-1,j])
		new_cell = cl.cell([i-1,j], current_dist + 1)
		new_cell.set_predecessor([i,j])
		index = new_cell.search_array(heap_vector)
		if index == None:
			#The heap doesn't contain this neighbor, so add it
			cell_heap.add(new_cell)
			grid[i-1,j] = 2
		elif current_dist + 1 < heap_vector[index].get_dist(): 
			cell_heap.decrease_priority(index, new_cell)
	
	if i+1 < height and grid[i+1,j] != 3 and grid[i+1,j] != 1: 
		new_cell = cl.cell([i+1,j], current_dist + 1)
		new_cell.set_predecessor([i,j])
		index = new_cell.search_array(heap_vector)
		if index == None:
			#The heap doesn't contain this neighbor, so add it
			cell_heap.add(new_cell)
			grid[i+1,j] = 2
		elif current_dist + 1 < heap_vector[index].get_dist(): 
			cell_heap.decrease_priority(index, new_cell)
	
	
	if j-1 >= 0 and grid[i,j-1] != 3 and grid[i,j-1] != 1: 
		new_cell = cl.cell([i,j-1], current_dist + 1)
		new_cell.set_predecessor([i,j])
		index = new_cell.search_array(heap_vector)
		if index == None:
			#The heap doesn't contain this neighbor, so add it
			cell_heap.add(new_cell)
			grid[i,j-1] = 2
		elif current_dist + 1 < heap_vector[index].get_dist(): 
			cell_heap.decrease_priority(index, new_cell)
	
	
	if j+1 < width and grid[i,j+1] != 3 and grid[i,j+1] != 1: 
		new_cell = cl.cell([i,j+1], current_dist + 1)
		new_cell.set_predecessor([i,j])
		index = new_cell.search_array(heap_vector)
		if index == None:
			#The heap doesn't contain this neighbor, so add it
			cell_heap.add(new_cell)
			grid[i,j+1] = 2
		elif current_dist + 1 < heap_vector[index].get_dist(): 
			cell_heap.decrease_priority(index, new_cell)
			
			
	plt.imshow(grid, cmap=colormap, norm=norm)		
	fig.canvas.draw()
	plt.pause(0.0001)


condition = True
while condition:
	grid[i,j] = 4
	index = cl.cell([i,j]).search_array(checked_cells)
	current_cell = checked_cells[index]
	if current_cell.get_predecessor() == None:
		condition = False
	else:
		[i,j] = current_cell.get_predecessor()	

plt.imshow(grid, cmap=colormap, norm=norm)
print("Dijkstra's algorithm run time:", end=" ")
print(time.time() - start)
plt.show()




"""
	if i+1 < height and grid[i+1,j] != 3 and grid[i+1,j] != 1: 
		new_cell = cl.cell([i+1,j])
		index = new_cell.search_array(heap_vector)
		if index == None:
			#The heap doesn't contain this neighbor, so add it
			cell_heap.add(cl.cell([i+1,j], current_dist + 1))
			grid[i+1,j] = 2
		elif current_dist + 1 < heap_vector[index].get_dist(): 
			cell_heap.decrease_priority(index, cl.cell([i+1,j], current_dist + 1))
	
	
	if j-1 >= 0 and grid[i,j-1] != 3 and grid[i,j-1] != 1: 
		new_cell = cl.cell([i,j-1])
		index = new_cell.search_array(heap_vector)
		if index == None:
			#The heap doesn't contain this neighbor, so add it
			cell_heap.add(cl.cell([i,j-1], current_dist + 1))
			grid[i,j-1] = 2
		elif current_dist + 1 < heap_vector[index].get_dist(): 
			cell_heap.decrease_priority(index, cl.cell([i,j-1], current_dist + 1))
	
	
	if j+1 < width and grid[i,j+1] != 3 and grid[i,j+1] != 1: 
		new_cell = cl.cell([i,j+1])
		index = new_cell.search_array(heap_vector)
		if index == None:
			#The heap doesn't contain this neighbor, so add it
			cell_heap.add(cl.cell([i,j+1], current_dist + 1))
			grid[i,j+1] = 2
		elif current_dist + 1 < heap_vector[index].get_dist(): 
			cell_heap.decrease_priority(index, cl.cell([i,j+1], current_dist + 1))
"""






