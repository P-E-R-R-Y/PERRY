import numpy as np
from scipy.spatial import Voronoi, voronoi_plot_2d
import matplotlib.pyplot as plt

# Define points
points = np.array([[0, 0.5], [1, 2], [2, 4.5], [3, 1], [4, 2], [5, 0.5]])

# Compute Voronoi diagram
vor = Voronoi(points)

# Plot the diagram
voronoi_plot_2d(vor)
#plt.scatter(points[:, 0], points[:, 1], color='red')  # Plot original points
plt.show()

# Voronoi points (vertices)
print("Voronoi points:", vor.vertices)