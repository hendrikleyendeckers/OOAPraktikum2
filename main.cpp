#include <iostream>
#include "PriorityQueue.h"

using namespace std;

void tt1(){
    PriorityQueue<int> pq;

    try {
        pq.extractMin();
    } catch (QueueException noElements) {
        cout << noElements.toString() << endl;
    }

    cout << "#" << pq.isEmpty() << "#" << endl;

    cout << "Hello" << endl;

    for (int i = 0, val = 0; i < 10; i++, val++) {
        pq.insert(val, i);
    }

    cout << "Hello2" << endl;

    int val0;
    val0 = pq.extractMin();

    try {
        pq.decreaseKey(0, 0);
    } catch (QueueException elemNotFound) {
        cout << elemNotFound.toString() << endl;
    }

    cout << "Hello3" << endl;

    int val1 = 2;
    pq.decreaseKey(val1, 0);


    cout << "Hello4" << endl;

    int val2 = 6;
    pq.remove(val2);

    cout << "Hello4" << endl;

    cout << "#" << pq.isEmpty() << "#" << endl;

    cout << "Hello5" << endl;
}

void tt2(){
    PriorityQueue<int> pq;
    for (int i = 0, val = 0; i < 100000; i++, val++) {
        pq.insert(val, i);
    }
    pq.extractMin();
    pq.isEmpty();
    pq.decreaseKey(10, 0);
    pq.remove(9);
    cout << "destruktor wird (automatisch) aufgerufen" << endl;
}

int main() {
    tt1();

    return 0;
}