import numpy as np
import matplotlib.pyplot as plt
import re
# import matplotlib.pyplot as plt

from sklearn import cluster
from sklearn.decomposition import PCA
# from sklearn.neighbors import neighbors_graph
# from sklearn.preprocessing import StandardScaler

data = np.zeros((10, 2016))
with open("input.txt", 'r') as f:
    i = 0
    for line in f:
        temp = re.split("\s", line)
        for j in range(10):
            data[j][i] = float(temp[j])
        i += 1

pca = PCA(n_components=50)
data_new = pca.fit_transform(data)
k_means = cluster.KMeans(n_clusters=2)
k_means.fit(data_new)
print(k_means.labels_)

graph = np.zeros((48, 42))
for w in range(10):
	for x in range(48):
		for y in range(42):
			graph[x][y] = data[w][x * 42 + y]
	plt.imshow(graph, cmap='gray')
	plt.show()