#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    queue<int> que;

public:
    MyQueue() {}

    void push(int x) { que.push(x); }

    int pop()
    {
        int result = que.front();
        que.pop();

        return result;
    }

    int peek() { return que.front(); }

    bool empty() { return que.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */