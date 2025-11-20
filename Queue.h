//
// Created by zen_1 on 2/11/2024.
//

#ifndef PROJECT2_QUEUE_H
#define PROJECT2_QUEUE_H
#include "Node.h"
#include <iostream>
using std::cout, std::endl;

/*
 * Queue class
 * All Nodes will point to the Node ?
 */
template<typename Object>
class Queue {
private:
    Node<Object>* front;
    Node<Object>* back;

public:
    // Constructor
    Queue() {
        // Start with an empty Queue
        back = nullptr;
        front = back;
    }

    // De-constructor
    ~Queue() {
        // Make sure no heap allocation
        while (front != nullptr && back != nullptr) {
            dequeue();
        }
        cout << "No memory leaks!" << endl;
    }

    // add Value to Queue
    void enqueue(Object item) {
        //Set first node to back
        if(back == nullptr)//first node added to stack
        {
            //store in heap memory
            Node<Object>* newNodePtr = new Node<Object>(item);
            front = newNodePtr;// first node is the front
            back = front; //only one item in queue
        }
        else {
            // Store the item in a Node in heap memory
            Node<Object> *newNodePtr = new Node<Object>(item);
            //previous back to point to the new item
            back->setNext(newNodePtr);
            //new item is now back
            back = newNodePtr;
        }
    }

    // Remove a value from the Queue
    // Returns the value being popped
    Object dequeue() {
        // Check that there is a Node to pop
        if (front == nullptr && back == nullptr) {
            // The Queue is empty
            return Object();
        }
        // Create a copy of the value to be returned
        Object item = front->getItem();
        // Store a copy of front
        Node<Object>* frontCopy = front;
        // Update front
        front = front->getNext();
        // Delete the Node from heap memory
        delete frontCopy;
        // Return the value being popped
        return item;
    }

    // Search for an item in the Queue
    // Return true if the item is in the Queue
    // Return false otherwise
    bool search(Object item) const {
        Node<Object>* topCopy = front;
        while (topCopy != nullptr) {
            if (topCopy->getItem() == item) {
                return true;
            }
            topCopy = topCopy->getNext();
        }
        return false;
    }

    // Print (list all the values in the Queue)
    void print() const {
        cout << "Front of Queue" << endl;
        Node<Object>* curr = front;
        while (curr != nullptr) {
            cout << curr->getItem() << endl;
            curr = curr->getNext();
        }
        cout << "Back of Queue" << endl;
    }
};
#endif //PROJECT2_QUEUE_H
