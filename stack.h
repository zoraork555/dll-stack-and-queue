#ifndef __STACK_H__
#define __STACK_H__

#include "exceptions.h"
#include "dll.h"

template <typename T>
class Stack {
private:
    Dll<T> S;
public:
    Stack() { // create an empty stack
        S = Dll<T>();
    }
    void push(T value) { // add an item to the top of the stack
        S.insert(0, value);
    }
    T pop() { // remove of the value at the top of the stack and return its value
        if (S.size()==0) throw InvalidOperationException("Stack empty.");
        return S.remove(0);
    }
    T peek() { // return the value at the top of the stack, keeping it in the stack
        if (S.size()==0) throw InvalidOperationException("Stack empty.");
        return S.at(0);
    }
    int size() const { return S.size(); } // return how many items are in the stack
    bool empty() const { return size()==0; } // return if the stack is empty
    void display(ostream &os) const { // write the contents of the stack to the ostream
        S.display(os);
    }
};

template <typename T>
ostream &operator<<(ostream &os, const Stack<T> &stack) { // write the contents of the stack to the ostream
    stack.display(os);
    return os;
}
#endif

