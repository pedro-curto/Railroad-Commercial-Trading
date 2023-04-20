# Railroad-Commercial-Trading

Here is a project made for a course named Analysis and Synthesis of Algorithms, in a group of two, in my second year in university.

The purpose is to maximize the value of commercial trades in the network while minimizing the costs of infrastructure, which means that only the strictly necessary sections will be financed to assure connections between as many regions as possible and only between those that already have commercial trades established.

Basically, this is solvable by building a planar non directed graph G=(V,E) such that V (vertices) represents the set of regions and E (edges) represents the connections between railroad stations of such regions.

The input given is the number of vertices, the number of edges and all the edges the graph contains. The expected output was the maximum value of commercial trades, while minimizing the infrastructure costs. 

This problem was solved through a spanning tree with Kruskal's algorithm, supported by disjoint sets.

The code was written in C++ in English. Like the tiling project (both required for the same course), it isn't commented because it is a small project, but the code is explained and analysed in the report file, written in Portuguese.
