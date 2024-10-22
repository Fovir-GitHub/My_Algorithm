#ifndef _NEWQUEUE_HPP_
#define _NEWQUEUE_HPP_

#include"newdelist.hpp"

template<typename T>
class NewQueue :public NewDeList<T>
{
public:
    bool push(T push_value) { return NewDeList<T>::push(push_value, NewDeList<T>::BACK); }
    bool pop() { return NewDeList<T>::pop(NewDeList<T>::FRONT); }
    T peek() { return NewDeList<T>::peek(NewDeList<T>::FRONT); }

    bool empty() { return NewDeList<T>::empty(); }
};

#endif // !_NEWQUEUE_HPP_