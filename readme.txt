This is a group project using cluster algorithm (TBD).

All codes are original.

To build the required executable file, use:
bash> make

the brutal-cluster is a cluster using k-means algorithm without principal component analysis, to build the brutal-cluster alone, type
bash> make brutal_cluster

similarly you may try out:
bash> make c_cluter
bash> make SFDP_cluster

to delete everything built from source, type:
bash> make clean

to run the program correctly, you have to copy data into a file called input.txt in the same directory as all the clusters are in. And use ./CLUSTER(which should be replaced by cluster name) to run the clustering process. The c_cluster often consumes the most time to compile, and also takes the longest time to generate result. BE PATIENT. the result will be written into a file called out.txt.

/******* This folder contains all files concerning the lab homework. *******/
eigen/
this folder is the matlab generated eigenvalue calculator. They are only indirectly called by the c_cluster program.

Makefile
(Intentionally left blank)

SFDP_clustering.cpp
this is the SFDP cluster using a genteel clustering algorithm published on the science magazine.

Sample Figure for SFDP.png
plotted using the matplotlib of python, used to illustrate the underlying reason for our clustering algorithm.

brutal_clustering.cpp
This is the brutal_clustering method, using only the k-means to generatebinary clustering.

c_clustering.cpp
A pca and better k-means algorithm is integrated.

clustering.py
A python program we wrote using the sklearn and numpy library. the logistic is that we use pca and k-means to cluster. The output doesn't have the required form, we only use this program as a benchmark function.

input.txt
A file which all out clusters read input from. if you want the clusters to work correctly

k-means.cpp
A file in which the k-means part of c_cluster is written.

k-means.h
The k-means header

output.txt
INTENTION: This is not the output file, our program write data into a file called out.txt

pca.cpp
the pca part of c_cluster

plot.py
to plot the clustering graph of our pcaed dataset.

readme.txt
/*THIS FILE*/
