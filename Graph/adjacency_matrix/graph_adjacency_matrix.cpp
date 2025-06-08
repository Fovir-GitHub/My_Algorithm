#include "graph_adjacency_matrix.h"
#include <iostream>
#include <stdexcept>

GraphAdjacencyMatrix::GraphAdjacencyMatrix(
    const std::vector<int> & vetices,
    const std::vector<std::vector<int>> & edges) {
    for (const int & v : vetices)
        AddVertex(v);

    for (const std::vector<int> & edge : edges)
        AddEdge(edge[0], edge[1]);
}

void GraphAdjacencyMatrix::AddVertex(int value) {
    int original_size = vetices.size();

    vetices.push_back(value);
    adjacency_matrix.emplace_back(std::vector<int>(original_size, 0));

    for (std::vector<int> & row : adjacency_matrix)
        row.push_back(0);

    return;
}

void GraphAdjacencyMatrix::AddEdge(int i, int j) {
    if (i * j < 0 || i >= Size() || j >= Size() || i == j)
        throw std::out_of_range("The vertex does not exist!");

    adjacency_matrix[i][j] = adjacency_matrix[j][i] = 1;
}

void GraphAdjacencyMatrix::RemoveVertex(int index) {
    if (index >= Size())
        throw std::out_of_range("The vertex is not exist!");

    vetices.erase(vetices.begin() + index);
    adjacency_matrix.erase(adjacency_matrix.begin() + index);
    for (std::vector<int> & row : adjacency_matrix)
        row.erase(row.begin() + index);

    return;
}

void GraphAdjacencyMatrix::RemoveEdge(int i, int j) {
    if (i * j <= 0 || i >= Size() || j >= Size() || i == j)
        throw std::out_of_range("The vertex does not exist!");

    adjacency_matrix[i][j] = adjacency_matrix[j][i] = 0;
}

void GraphAdjacencyMatrix::Print() {
    std::cout << "Vectex:\n";
    for (const int & v : vetices)
        std::cout << v << '\n';

    std::cout << "\nEdges:\n";
    for (const std::vector<int> & row : adjacency_matrix) {
        for (const int & column : row)
            std::cout << column << ' ';
        std::cout << '\n';
    }

    return;
}
