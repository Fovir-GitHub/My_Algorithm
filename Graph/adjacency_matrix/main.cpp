#include "graph_adjacency_matrix.h"
#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> vetices = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> edges = {
        {1, 2}, {2, 4}, {2, 4}, {3, 1}, {0, 3},
    };

    GraphAdjacencyMatrix graph(vetices, edges);
    graph.Print();

    return 0;
}