#include "adjacency.h"
#include<iostream>

static void showLinkListNode(int value);

LinkListNode::~LinkListNode()
{
    Node * backup = nullptr;
    while (head)
    {
        backup = head->next;
        delete head;
        head = backup;
    }
}

bool LinkListNode::push(int push_value)
{
    if (empty())
    {
        head = new Node(push_value);
        return true;
    }

    Node * visit = head;
    while (visit->next)
    {
        if (visit->value == push_value)
            return false;
        visit = visit->next;
    }

    Node * push_node = new Node(push_value);
    visit->next = push_node;

    return true;
}

bool LinkListNode::remove(int remove_value)
{
    if (empty())
        return false;

    Node * current = head;
    Node * previous = nullptr;

    while (current)
    {
        if (current->value == remove_value)
            break;
        previous = current;
        current = current->next;
    }

    if (!current)
        return false;

    previous->next = current->next;
    delete current;

    return true;
}

void LinkListNode::Traverse(void(*func)(int))
{
    for (Node * visit = head; visit; visit = visit->next)
        func(visit->value);

    return;
}

void AdjacencyList::AddVertex(int vertex_number)
{
    if (!NotExist(vertex_number))
        return;

    graph.insert(std::pair<int, LinkListNode>(vertex_number,
        LinkListNode(vertex_number)));

    return;
}

void AdjacencyList::RemoveVertex(int vertex_number)
{
    if (NotExist(vertex_number))
        return;

    graph.erase(vertex_number);
    for (auto & x : graph)
        x.second.remove(vertex_number);

    return;
}

void AdjacencyList::AddEdge(int first_vertex, int second_vertex)
{
    if (NotExist(first_vertex) || NotExist(second_vertex)
        || first_vertex == second_vertex)
        return;

    graph[first_vertex].push(second_vertex);
    if (IsUndirected())
        graph[second_vertex].push(first_vertex);

    return;
}

void AdjacencyList::RemoveEdge(int first_vertex, int second_vertex)
{
    if (NotExist(first_vertex) || NotExist(second_vertex))
        return;

    graph[first_vertex].remove(second_vertex);
    if (IsUndirected())
        graph[second_vertex].remove(first_vertex);

    return;
}

void AdjacencyList::Show()
{
    for (auto & x : graph)
    {
        std::cout << x.first << " linked with: ";
        x.second.Traverse(showLinkListNode);
        std::cout << '\n';
    }

    return;
}

void showLinkListNode(int value)
{
    std::cout << value << ' ';
    return;
}
