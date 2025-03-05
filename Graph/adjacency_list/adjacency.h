#ifndef _ADJACENCY_H_
#define _ADJACENCY_H_

#include <map>
#include <unordered_set>
#include <vector>

class LinkListNode
{
private:
    struct Node
    {
        Node * next;
        int    value;

        Node(int v) : value(v) { next = nullptr; }
    };

    int    node_value;
    Node * head;

public:
    LinkListNode(int nv = 0) : node_value(nv) { head = nullptr; }
    ~LinkListNode();

    bool empty() const { return head == nullptr; }
    bool push(int push_value);
    bool remove(int remove_value);

    int    GetNodeValue() const { return node_value; }
    Node * GetHead() const { return head; }

    void Traverse(void (*func)(int));
};

class AdjacencyList
{
private:
    std::map<int, LinkListNode> graph;
    int                         mode;

public:
    enum { UNDIRECTED, DIRECTED };

    AdjacencyList(int m = UNDIRECTED) : mode(m) {}
    ~AdjacencyList() { graph.clear(); }

    unsigned int Size() const { return graph.size(); }
    bool         Empty() const { return Size() == 0; }
    bool         IsUndirected() const { return mode == UNDIRECTED; }
    bool         NotExist(int check_number) const
    {
        return graph.find(check_number) == graph.end();
    }

    void AddVertex(int vertex_number);
    void RemoveVertex(int vertex_number);

    void AddEdge(int first_vertex, int second_vertex);
    void RemoveEdge(int first_vertex, int second_vertex);

    void                      Show();
    typename std::vector<int> BFSGraph(int start_vertex);
    typename std::vector<int> DFSGraph(int start_vertex);
    void DFSHelper(std::unordered_set<int> & visited, std::vector<int> & res,
                   int vertex);
};

#endif // !_ADJACENCY_H_