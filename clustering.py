import numpy as np
import re
# import matplotlib.pyplot as plt

from sklearn import cluster
from sklearn.decomposition import PCA
# from sklearn.neighbors import neighbors_graph
# from sklearn.preprocessing import StandardScaler

data = np.zeros((10, 2016))
with open("../input.txt", 'r') as f:
    i = 0
    for line in f:
        temp = re.split("\s", line)
        for j in range(10):
            data[j][i] = float(temp[j])
        i += 1

np.random.seed(0)
pca = PCA(n_components=50)
data_new = pca.fit_transform(data)
k_means = cluster.KMeans(n_clusters=2)
k_means.fit(data_new)
print(k_means.labels_)
