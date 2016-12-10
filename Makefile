CC = g++
CFLAGS = -g -w
all: c_cluster brutal_cluster

c_cluster: c_clustering.cpp pca.cpp
	$(CC) $(CFLAGS) c_clustering.cpp pca.cpp -o c_cluster

brutal_cluster:
	$(CC) $(CFLAGS) brutal_clustering.cpp -o brutal_cluster

clean:
	rm c_cluster
	rm brutal_cluster
	rm -rf *.dSYM
