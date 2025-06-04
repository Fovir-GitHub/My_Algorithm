#include <iostream>
#include <vector>

class Graph
{
private:
    int                            vertices;
    std::vector<std::vector<bool>> graph;

public:
    Graph(int v)
        : vertices(v)
        , graph(std::vector<std::vector<bool>>(
              vertices, std::vector<bool>(vertices, false)))
    {
    }

    ~Graph() {}

    void GetEdges(int edges);
    void Show();
};

void Graph::GetEdges(int edges)
{
    for (int i = 0; i < edges; i++)
    {
        int v_1, v_2;

        std::cout << "Enter edge " << i + 1 << ": ";
        std::cin >> v_1 >> v_2;
        graph[v_1][v_2] = graph[v_2][v_1] = true;
    }

    return;
}

void Graph::Show()
{
    for (const auto & row : graph)
    {
        for (const auto & column : row) std::cout << column << ' ';
        std::cout << '\n';
    }

    return;
}

int main(void)
{
    int vertices = 0, edges = 0;

    std::cout << "Enter number of vertices: ";
    std::cin >> vertices;
    std::cout << "Enter number of edges: ";
    std::cin >> edges;

    Graph graph(vertices);
    graph.GetEdges(edges);

    graph.Show();

    return 0;
}