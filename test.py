import numpy as np
import matplotlib.pyplot as plt
import sys

if len(sys.argv) != 3:
  print("Usage: python <scriptName> <datasetName>")

dataset = np.loadtxt(sys.argv[1],delimiter=" ")
print(dataset)

plt.scatter(dataset[:,0],dataset[:,1],s=[0.2]*len(dataset))

centres = np.loadtxt(sys.argv[2],delimiter=" ")

plt.scatter(centres[:,0],centres[:,1],s=[15]*len(centres))
plt.show()
