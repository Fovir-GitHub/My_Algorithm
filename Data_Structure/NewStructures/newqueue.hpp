#ifndef _NEWQUEUE_HPP_
#define _NEWQUEUE_HPP_

#include"newdelist.hpp"

template<typename T>
class NewQueue :public NewDeList<T>
{
public:
    bool push(T push_value) { return NewDeList<T>::push_back(push_value); }
    bool pop() { return NewDeList<T>::pop_front(); }
    T peek()const { return NewDeList<T>::peek_front(); }

    bool empty()const { return NewDeList<T>::empty(); }
};

#endif // !_NEWQUEUE_HPP_