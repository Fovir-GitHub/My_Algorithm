#include<iostream>
#include<cstdlib>
#include<ctime>
#include"adjacency.h"

int main(void)
{
    const int VERTEX_MAX = 10;
    int first_v = 0, second_v = 0;
    AdjacencyList adj(AdjacencyList::DIRECTED);

    for (int i = 1; i <= VERTEX_MAX; i++)
        adj.AddVertex(i);

    while (std::cin >> first_v >> second_v)
        adj.AddEdge(first_v, second_v);

    adj.Show();

    return 0;
}