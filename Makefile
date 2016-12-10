CC = g++
CFLAGS = -g -w
all: c_cluster

c_cluster: c_clustering.cpp pca.cpp
	$(CC) $(CFLAGS) c_clustering.cpp pca.cpp -o c_cluster

clean:
	rm c_cluster
	rm -rf *.dSYM
