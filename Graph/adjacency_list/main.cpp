#include "adjacency.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void) {
    std::freopen("./graph.in", "r", stdin);

    const int VERTEX_MAX = 5;
    int first_v = 0, second_v = 0;
    AdjacencyList adj;

    for (int i = 1; i <= VERTEX_MAX; i++)
        adj.AddVertex(i);

    while (std::cin >> first_v >> second_v)
        adj.AddEdge(first_v, second_v);

    adj.Show();
    std::cout << '\n';

    std::vector<int> travrse_result = adj.BFSGraph(1);
    for (auto & x : travrse_result)
        std::cout << x << ' ';
    std::cout << '\n';
    travrse_result = adj.DFSGraph(5);
    for (auto & x : travrse_result)
        std::cout << x << ' ';
    return 0;
}