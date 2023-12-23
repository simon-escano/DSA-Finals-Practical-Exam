// Implement the SinglyQueue here
#include "queue.h"
#include "linkedlist.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class SinglyQueue : public Queue {
    LinkedList* queue;
    
    public:
    SinglyQueue() {
        queue = new LinkedList();
    }
    
	virtual void enqueue(string elem) {
        queue->addTail(elem);
    }
	virtual string dequeue() {
        if (isEmpty()) {
            return "(none)";
        }
        return queue->removeHead();
    }
	virtual string first() {
        if (isEmpty()) return "(none)";
        return queue->get(0);
    }
	virtual int size() {
        return queue->_size();
    }
	virtual bool isEmpty() {
        return queue->_size() == 0;
    }
	virtual void print() {
        queue->print();
    }
};