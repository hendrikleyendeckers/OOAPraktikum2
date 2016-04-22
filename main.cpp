#include <iostream>
#include <ctime>
#include <cstdlib>
#include "PriorityQueue.h"

using namespace std;

void tt1(){
    PriorityQueue<int> pq;

    try {
        pq.extractMin();
    } catch (QueueException e) {
        cout << e.toString() << endl;
    }

    cout << "#" << pq.isEmpty() << "#" << endl;

    cout << "Hello" << endl;

    for (int i = 0; i < 10; i++) {
        pq.insert(i, i);
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
    for (int i = 0; i < 100000; i++) {
        pq.insert(i, i);
    }
    pq.extractMin();
    pq.isEmpty();
    pq.decreaseKey(10, 0);
    pq.remove(9);
    cout << "destruktor wird (automatisch) aufgerufen" << endl;
}

void testPraktikum() {
    int MAX = 100;
    int i;
    clock_t tic, toc;

    PriorityQueue<int> pq;

    srand(time(NULL));

    tic = clock();
    for(i = 0; i < MAX; ++i) {
        pq.insert((rand() % (100000 + 1)), MAX - i);
    }
    toc = clock();

    cout << "insertion time: "  << (float)(toc-tic) / CLOCKS_PER_SEC << endl;

    tic = clock();
    for(i = 0; i < MAX; ++i) {
        pq.extractMin();
    }
    toc = clock();

    cout << "extract time: "  << (float)(toc-tic) / CLOCKS_PER_SEC << endl;
}

int main() {
    tt1();
//    tt2();
//    testPraktikum();

    return 0;
}