#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

typedef struct {
    int v1;
    int v2;
    int w;
}edge;

std::vector<int> parent;
std::vector<int> rank;

int findset(int x){
    if (parent[x] != x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

void link(int x, int y){
    if (rank[x] > rank[y])
        parent[y] = x;
    else{
        parent[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;
    }
}

void unions(int x, int y){
    link(findset(x),findset(y));
}

int compare_weight(edge x, edge y){ 
    return x.w > y.w;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n_vertices, n_arcos;
    long unsigned soma = 0;

    std::cin >> n_vertices >> n_arcos;

    if (n_arcos == 0 || n_vertices == 1){
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<edge> edges(n_arcos);

    for(int i = 0; i < n_arcos;i++){
        edge e;
        std::cin >> e.v1 >> e.v2 >> e.w;
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), compare_weight);

    for(int i = 0; i <= n_vertices;i++){
        parent.push_back(i);
        rank.push_back(0);
    }

    for (int i = 0; i < n_arcos;i++){
        if (findset(edges[i].v1) != findset(edges[i].v2)){
            unions(edges[i].v1, edges[i].v2);
            soma += edges[i].w;
        }
    }

    std::cout << soma << std::endl;

    return 0;
}