#include "Stack.h"
#include "Queue.h"
#include "Turbine.h"
#include <vector>
#include <iostream>
using namespace std;


int main() {
    //Create Queue object of type String
    bool searched;

    Queue<string> q1;
    q1.enqueue("A");
    q1.enqueue("B");
    q1.print();
    cout << q1.search("B") << endl;
    cout << q1.search("D") << endl;
    cout << q1.search("A") << endl;
    q1.dequeue();
    q1.dequeue();
    q1.print();
    cout << "" << endl;
    //Create Queue objects of type Int
    Queue<int> q2;
    q2.enqueue(1);
    q2.enqueue(2);
    q2.print();
    cout << q2.search(1) << endl;
    cout << q2.search(4) << endl;
    cout << q2.search(2) << endl;
    q2.dequeue();
    q2.dequeue();
    q2.print();
    cout << "" << endl;

    //Create Queue  and a Stack object of type Turbine
    vector<Turbine> turbines;

    if(getDataFromFile(turbines)) {
        // Enqueue first 10 items of vector in Queue and print
        Queue<Turbine> q3;
        for (int i = 0; i < 10; ++i) {
            q3.enqueue(turbines[i]);
        }
        q3.print(); //all elements printed
        cout << "" << endl;
        //Dequeue 10 items and push to Stack
        Stack<Turbine> s1;
        for (int i = 0; i < 10; ++i) {
            q3.dequeue();
            s1.push(turbines[i]);
        }
        q3.print(); //empty queue
        cout << "" << endl;
        cout << "" << endl;
        s1.print(); //all elements printed
        cout << "" << endl;
        //Pop all items from stack
        for (int i = 0; i < 11; ++i) {
            s1.pop();
        }
        s1.print(); //empty stack
    }
    return 0;
}
