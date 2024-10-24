#ifndef _MYHEAP_HPP_
#define _MYHEAP_HPP_

#include<vector>
#include<algorithm>
using std::vector;

template<typename T>
class MyHeap
{
private:
    vector<T> heap;

public:
    MyHeap() {}
    MyHeap(vector<T> input_heap);

    void push(T push_value);
    bool empty() { return heap.empty(); }
    T peek() { return heap[0]; }
    void pop();

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void SiftUp(int i);
    void SiftDown(int i);
};

template<typename T>
MyHeap<T>::MyHeap(vector<T> input_heap)
{
    heap = input_heap;
    for (int i = parent(heap.size() - 1); i >= 0; i--)
        SiftDown(i);
}

template<typename T>
void MyHeap<T>::push(T push_value)
{
    heap.push_back(push_value);
    SiftUp(heap.size() - 1);

    return;
}

template<typename T>
void MyHeap<T>::pop()
{
    if (empty())
        return;

    std::swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();

    SiftDown(0);

    return;
}

template<typename T>
void MyHeap<T>::SiftUp(int i)
{
    while (true)
    {
        int p = parent(i);

        if (p < 0 || heap[i] <= heap[p])
            break;
        std::swap(heap[i], heap[p]);
        i = p;
    }

    return;
}

template<typename T>
void MyHeap<T>::SiftDown(int i)
{
    while (true)
    {
        int l = left(i), r = right(i), ma = i;
        if (l<heap.size() && heap[l]>heap[ma])
            ma = l;
        if (r<heap.size() && heap[r]>heap[ma])
            ma = r;
        if (ma == i)
            break;

        std::swap(heap[i], heap[ma]);

        i = ma;
    }

    return;
}

#endif // !_MYHEAP_HPP_