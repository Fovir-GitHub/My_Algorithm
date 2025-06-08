#ifndef _GRAPH_ADJACENCY_MATRIX_H_
#define _GRAPH_ADJACENCY_MATRIX_H_

#include <vector>

class GraphAdjacencyMatrix {
private:
    std::vector<int> vetices;
    std::vector<std::vector<int>> adjacency_matrix;

public:
    GraphAdjacencyMatrix() {}
    GraphAdjacencyMatrix(const std::vector<int> & vetices,
                         const std::vector<std::vector<int>> & edges);

    const int Size() const { return vetices.size(); }

    void AddVertex(int value);
    void AddEdge(int i, int j);

    void RemoveVertex(int index);
    void RemoveEdge(int i, int j);

    void Print();
};

#endif // !_GRAPH_ADJACENCY_MATRIX_H_