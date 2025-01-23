#ifndef _NEWSTACK_HPP_
#define _NEWSTACK_HPP_

#include "newdelist.hpp"

template <typename T> class NewStack : public NewDeList<T>
{
public:
    bool push(T push_value) { return NewDeList<T>::push_back(push_value); }
    bool pop() { return NewDeList<T>::pop_back(); }
    T peek() const { return NewDeList<T>::peek_back(); }
};

#endif // !_NEWSTACK_HPP_