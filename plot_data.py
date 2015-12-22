#!/usr/bin/python # Standard command line to start python script. '!/usr/bin/python' is the local Python's address.

# Imports libraries
import sys #receives inputs from a terminal command line
import numpy as np # Math library
import pandas as pd # Math library
import matplotlib # Matplotlib plotting library
matplotlib.use('Agg') # Matplotlib plotting library
import matplotlib.pyplot as plt # Matplotlib plotting library

# Beginning of the script operations
d = pd.read_csv(sys.argv[1]) # Reads the csv file informed as the second argument on the terminal command line
figure = str(sys.argv[1])[:-3] + "jpg" # Defines the name of the output jpg file from the name of the input csv file
sizex=d[' y'][d[' y']==max(d[' y'])].count() # Defines the number of no repeated elements in d['x'], which is the same as the number of times a single element is repeated in d[' y']
sizey=d['x'][d['x']==max(d['x'])].count() # Defines the number of no repeated elements in d[' y'], as done for sizex before
x=np.reshape(d['x'],(sizex,sizey))[0,:].transpose() # Creates a numpy array with no repeated elements of d['x']
y=np.reshape(d[' y'],(sizex,sizey))[:,0] # Creates a numpy array with no repeated elements of d[' y']
z=np.reshape(d[' out'],(sizex,sizey)) # Creates an appropriated matrix version of d[' out']
plt.pcolormesh(x,y,z, cmap = plt.cm.hot) # Plots the treated version of the received data
plt.colorbar() # Includes colorbar to the plot
plt.savefig(figure) # Saves the plot to an external file with the name saved in the string 'figure'


