# dll-stack-and-queue
This project implements three abstract data types (ADTs) - doubly linked list (dll), stack, and queue template classes. The stack and queue use the dll internally. All operations have an efficient runtime. Besides display(), all stack and queue operations run in O(1). It is recommended to first write the ADTs using a primitive data type before making the ADTs templates. 

## Functions
- DLL
  - Dll - create new dll, deep copy another dll, or create new dll from list
  - insert - insert a value at the rank/index
  - remove - remove the node at the rank/index and return its value
  - at - return a reference to the value of the list at a rank/index
  - size - return how many items are in the list in O(1)
  - empty - return if the list is empty in O(1)
  - clear - reset the list to an empty list
  - display - write the contents of the list to the ostream
- Stack
  - Stack - create an empty stack
  - push - add an item to the top of the stack
  - pop - remove the value at the top of the stack and return its value
  - peek - return the value at the top of the stack, keeping it in the stack
  - size - return how many items are in the stack
  - empty - return if the stack is empty
  - display - write the contents of the stack to the ostream
- Queue
  - Queue - create an empty queue
  - enqueue - add an item to the back of the queue
  - dequeue - remove the value at the front of the queue and return its value
  - peek - return the value at the front of the queue, keeping it in the queue
  - size - return how many items are in the queue
  - empty - return if the queue is empty
  - display - write the contents of the queue to the ostream
- display operator - all three data structures have an override to the '<<' operator, so that each can be printed directly to the ostream
  - example: "cout << stack_var;" 

## Displaying 
When displaying a list, it should appear with the head on the left and the tail on the right.  
For example, the list 1 -> 2 -> 3 should display as follows:  
> [ 1 2 3 ]  

When displaying a stack, it should appear with the top on the left and the bottom on the right. 
For example, the stack created after push(1), push(2), push(3) should display as follows:  
> [ 3 2 1 ] 

When displaying a queue, it should appear with the front on the left and the back on the right. 
For example, the queue created after enqueue(1), enqueue(2), enqueue(3) should display as follows:  
> [ 1 2 3 ] 

## Exceptions 
Two exception classes are found in exceptions.h: InvalidOperationException and IndexOutOfRangeException.  
The exceptions follow the guidlines listed below:  
- List: throw IndexOutOfRangeException for the following operations: 
  - at(): when accessing an index outside the bounds of the linked list with the message "at(): Index was outside the bounds of the linked list." 
  - insert(): when index is not in the range from 0 to size (inclusive) with the message "insert(): Index was outside the bounds of the linked list." 
  - remove(): when removing an index outside the bounds of the linked list with the message "remove(): Index was outside the bounds of the linked list." 
- Stack: throw InvalidOperationException with the message "Stack empty." when popping or peeking an empty stack. 
- Queue: throw InvalidOperationException with the message "Queue empty." when dequeuing or peeking an empty queue. 

## Files 
interface.cpp is a command-line interface that can be used to test the data structures.  
dll.h, stack.h, and queue.h contain the commands for the respective ADT classes.  
exceptions.h contains two exception classes.  
a.exe is a compiled version of this project.  

## Running
To compile this program run the following code:
> g++ -Wall -std=c++11 interface.cpp -I . -o a  
> ./a
