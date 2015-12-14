#!/usr/bin/python

import sys
import pandas as pd
import os
import matplotlib.pyplot as plt
import numpy as np

for file in sys.argv:
	if "csv" not in file:
		continue
	print "load data from "+file
	df = pd.DataFrame.from_csv(file, index_col=None)
	df.columns=['x', 'y' , 'one']
	x = df['x'].values
	y = df['y'].values
	heatmap, xedges, yedges = np.histogram2d(x, y, bins=17)
	extent = [xedges[0], xedges[-1], yedges[0], yedges[-1]]

	plt.clf()
	plt.imshow(heatmap, extent=extent)
	plt.savefig(os.path.splitext( os.path.basename(file))[0]+'.jpg')
