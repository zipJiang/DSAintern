CC = g++
CFLAGS = -g -w
all: c_cluster brutal_cluster SFDP_cluster

c_cluster: c_clustering.cpp pca.cpp
	$(CC) $(CFLAGS) c_clustering.cpp pca.cpp k_means.cpp eigen/*.cpp -o c_cluster

brutal_cluster:
	$(CC) $(CFLAGS) brutal_clustering.cpp -o brutal_cluster

SFDP_cluster:
	$(CC) $(CFLAGS) SFDP_clustering.cpp -o SFDP_cluster

clean:
	rm *cluster
	rm -rf *.dSYM
	rm out.txt
	rm output.txt
