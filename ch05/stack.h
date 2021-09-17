#ifndef __STACK_H_
#define __STACK_H_

#include <vector>
#include <string>
#include <iostream>
using std::ostream;
using std::vector;
using ElemType = std::string;
using std::cout;

class Stack
{
public:
    Stack(int capacity = 0) : top_(0)
    {
        if (capacity)
        {
            stack_.reserve(capacity);
        }
    }
    virtual ~Stack()
    {
    }
    int size() const { return stack_.size(); }
    bool empty() const { return !top_; }
    bool full() const { return size() >= stack_.max_size(); }
    int top() const { return top_; }

    void print(ostream &os = cout) const;
    bool pop(ElemType &elem);
    bool push(const ElemType &elem);
    virtual bool peek(int index, ElemType &elem) { return false; }

protected:
    vector<ElemType> stack_;
    int top_;
};


#endif