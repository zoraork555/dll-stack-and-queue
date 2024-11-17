#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "exceptions.h"
#include "dll.h"

template <typename T>
class Queue {
private:
    Dll<T> Q;
public:
    Queue() { // create an empty stack
        Q = Dll<T>();
    }
    void enqueue(T value) { // add an item to the back of the queue
        Q.insert(Q.size(), value);
    }
    T dequeue() { // remove the value at the front of the queue and return its value 
        if (Q.size()==0) throw InvalidOperationException("Queue empty.");
        return Q.remove(0);
    }
    T peek() { // return the value at the front of the queue, keeping it in the queue
        if (Q.size()==0) throw InvalidOperationException("Queue empty.");
        return Q.at(0);
    }
    int size() const { return Q.size(); } // return how many items are in the queue
    bool empty() const { return size()==0; } // return if the queue is empty
    void display(ostream &os) const { // write the contents of the queue to the ostream
        Q.display(os);
    }
};

template <typename T>
ostream &operator<<(ostream &os, const Queue<T> &queue) { // write the contents of the queue to the ostream
    queue.display(os);
    return os;
}
#endif