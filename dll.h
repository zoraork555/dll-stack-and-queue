#ifndef __DLL_H__
#define __DLL_H__

#include "exceptions.h"

template <typename T>
class DllNode {
public:
    DllNode(const T &v = T(), DllNode *p = NULL, DllNode *n = NULL) : value(v), prev(p), next(n) {}
    ~DllNode() {}
    T value;
    DllNode *prev;
    DllNode *next;
};

template <typename T>
class Dll {
private:
    int crimp=0;
    DllNode<T> *head;
    DllNode<T> *tail;
public:
    Dll() : crimp(0) { // create an empty list
        head = new DllNode<T>();
        tail = new DllNode<T>();
    }
    Dll(const Dll &src) { // create a deep copy of the src list
        DllNode<T> *i = new DllNode<T>;
        for (i = src.head->next; i!=NULL; i=i->next) {
            if (i == src.head->next) {
                head = new DllNode<T>();
                tail = new DllNode<T>();
                DllNode<T> *temp = new DllNode<T>(i->value);
                head->next = temp;
                tail->prev = temp;
                crimp=1;
            }
            else {
                DllNode<T> *temp = new DllNode<T>(i->value, tail->prev, NULL);
                tail->prev->next = temp;
                tail->prev = temp;
                crimp++;
            }
        }
    }
    Dll(const T arr[], int size) { // create a linked list containing the elements of the array
        for (int i=0; i<size; i++) {
            if (i == 0) {
                head = new DllNode<T>();
                tail = new DllNode<T>();
                DllNode<T> *temp = new DllNode<T>(arr[i]);
                head->next = temp;
                tail->prev = temp;
                crimp=1;
            }
            else {
                DllNode<T> *temp = new DllNode<T>(arr[i], tail->prev, NULL);
                tail->prev->next = temp;
                tail->prev = temp;
                crimp++;
            }
        }
    }
    Dll &operator=(const Dll &src) { // create a deep copy of the src list
        DllNode<T> *i = new DllNode<T>;
        for (i = src.head->next; i!=NULL; i=i->next) {
            if (i == src.head->next) {
                head = new DllNode<T>();
                tail = new DllNode<T>();
                DllNode<T> *temp = new DllNode<T>(i->value);
                head->next = temp;
                tail->prev = temp;
                crimp=1;
            }
            else {
                DllNode<T> *temp = new DllNode<T>(i->value, tail->prev, NULL);
                tail->prev->next = temp;
                tail->prev = temp;
                crimp++;
            }
        }
        return *this;
    }
    ~Dll() { // free all memory
        clear();
        delete head;
        delete tail;
    }

    bool empty() const { return (head->next==NULL); } // return if the list is empty in O(1)
    int size() const { return crimp; } // return how many items are in the list in O(1)
    
    T &at(int rank) { // return a reference to the value of the list at a rank/index
        if ((rank < 0) || (rank > crimp-1) || (crimp == 0)) throw IndexOutOfRangeException("at(): Index was outside the bounds of the linked list.", rank);
        if (rank == 0) { //head
            return head->next->value;
        }
        else if (rank == size()-1) { //tail
            return tail->prev->value;
        }
        else {
            DllNode<T> *hu = head->next;
            for (int i=0; i<rank; i++) {
                hu = hu->next;
            }
            return hu->value;
        }
    }
    void insert(int rank, T value) { // insert a value at the rank/index
        if (rank < 0 || rank > crimp) throw IndexOutOfRangeException("insert(): Index was outside the bounds of the linked list.", rank);
        if (empty()) { //empty
            head = new DllNode<T>();
            tail = new DllNode<T>();
            DllNode<T> *temp = new DllNode<T>(value);
            head->next = temp;
            tail->prev = temp;
            crimp++;
        }
        else if (rank == 0) { //head
            DllNode<T> *temp = new DllNode<T>(value, NULL, head->next);
            head->next->prev = temp;
            head->next = temp;
            crimp++;
        }
        else if (rank == crimp) { //tail
            DllNode<T> *temp = new DllNode<T>(value, tail->prev, NULL);
            tail->prev->next = temp;
            tail->prev = temp;
            crimp++;
        }
        else { //middle
            DllNode<T> *hu = head->next;
            for (int i=0; i<rank; i++) {
                hu = hu->next;
            }
            DllNode<T> *temp = new DllNode<T>(value, hu->prev, hu);
            hu->prev->next = temp;
            hu->prev = temp;
            crimp++;
        }
    }
    T remove(int rank) { // remove the node at the rank/index and return its value
        if ((rank < 0) || (rank > crimp-1) || (crimp == 0)) throw IndexOutOfRangeException("remove(): Index was outside the bounds of the linked list.", rank);
        DllNode<T> *hu;
        if (rank==0) {
            hu = head->next;
            head->next = head->next->next;
            crimp--;
            return hu->value;
        }
        else if (rank==size()-1) {
            hu = tail->prev;
            tail->prev->prev->next = NULL;
            tail->prev = tail->prev->prev;
            crimp--;
            return hu->value;
        }
        else {
            hu = head->next;
            for (int i=0; i<rank; i++) {
                hu = hu->next;
            }
            hu->prev->next = hu->next;
            hu->next->prev = hu->prev;
            hu->prev = hu->next = NULL;
            crimp--;
            return hu->value;
        }
    }

    void clear() { head->next = NULL; tail->prev = NULL; crimp=0; } // reset the list to an empty list
    void display(ostream &os) const { // write the contents of the list to the ostream
        os << "[";
        DllNode<T> *i = new DllNode<T>;
        for (i = head->next; i!=NULL; i=i->next) {
            os << " " << i->value;
        }
        os << " ]";
    }
};

template <typename T>
ostream &operator<<(ostream &os, const Dll<T> &list) { // write the contents of the list to the ostream
    list.display(os);
    return os;
}
#endif
