#ifndef _NEWQUEUE_HPP_
#define _NEWQUEUE_HPP_

#include "newdelist.hpp"

template <typename T> class NewQueue : public NewDeList<T>
{
public:
    bool push(T push_value) { return this->push_back(push_value); }
    bool pop() { return this->pop_front(); }
    T    peek() const { return this->peek_front(); }
};

#endif // !_NEWQUEUE_HPP_