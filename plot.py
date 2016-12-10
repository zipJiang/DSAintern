import matplotlib.pyplot as plt
import numpy as np
import re


with open("output.txt", 'r') as f:
    i = 0
    x = np.arange(0, 250)
    y = np.arange(0, 250)
    for line in f:
        temp = re.split("\s", line)
        x[i] = float(temp[0])
        y[i] = float(temp[1])
        i += 1
    plt.plot(x, y, 'ro')
    plt.show()
