#include <iostream>
#include <ctime>
#include <cstdlib>
#include "PriorityQueue.h"

using namespace std;

//#define MAX 22500
#define MAX 100000

int testKai() {
    PriorityQueue<int> *queue;

    int valInt1[] = {1, 2, 3, 4, 5, 6};
    int valInt2[] = {7, 8, 9, 10};

    float prio1[] = {15, 30, 10, 45, 5, 40};
    float prio2[] = {25, 20, 35, 50};

    clock_t tic, toc;



    /**
     * QUEUE TEST
     */

    queue = new PriorityQueue<int>();

    cout << "\nInsert some entries to queue" << endl;
    for (int i = 0; i < 6; i++) {
        queue->insert(valInt1[i], prio1[i]);
    }
    queue->printQueue();

    cout << "\nInsert some more entries to queue" << endl;
    for (int i = 0; i < 4; i++) {
        queue->insert(valInt2[i], prio2[i]);
    }
    queue->printQueue();

    try {
        cout << "\nExtract value with highest priority in queue" << endl;
        cout << "Value = " << queue->extractMin() << endl;
        queue->printQueue();
    } catch (QueueException e) {
        cout << e.getError() << endl;
        return EXIT_FAILURE;
    }

    try {
        cout << "\nDecrease priority-value of value \"10\"" << endl;
        queue->decreaseKey(valInt2[3], 1);
        queue->printQueue();
    } catch (QueueException e) {
        cout << e.getError() << endl;
    }

    cout << "\nRemove entry with value \"4\"" << endl;
    queue->remove(valInt1[3]);
    queue->printQueue();

    delete (queue);
    cout << "\nQueue successfully destroyed" << endl;



    /**
     * EXCEPTIONS TEST
     */

    queue = new PriorityQueue<int>();

    cout << "\nQueueExceptions test for \"extractMin\"" << endl;
    try {
        cout << "Extract value with highest priority in queue" << endl;
        cout << "Value = " << queue->extractMin() << endl;
        queue->printQueue();
    } catch (QueueException e) {
        cout << e.getError() << endl;
    }

    cout << "\nQueueExceptions test for \"decreaseKey\"" << endl;
    try {
        cout << "Decrease priority-value of value \"20\"" << endl;
        queue->decreaseKey(20, 1);
        queue->printQueue();
    } catch (QueueException e) {
        cout << e.getError() << endl;
    }

    delete (queue);
    cout << "\nQueue successfully destroyed" << endl;



    /**
     * TIME MEASURING
     */

    queue = new PriorityQueue<int>();

    cout << "\nMeasuring time for function pqueue_insert() ..." << endl;
    tic = clock();
    for (int i = 0; i < MAX; ++i) {
        queue->insert(rand() % 1000, rand() % 100);
    }
    toc = clock();
    cout << "Insertion time: " << ((float) (toc - tic) / CLOCKS_PER_SEC) << endl;
//    queue->printQueue();

    cout << "\nMeasuring time for function pqueue_extractMin() ..." << endl;
    tic = clock();
    for (int i = 0; i < MAX; ++i) {
        queue->extractMin();
    }
    toc = clock();
    cout << "Extract time: " << ((float) (toc - tic) / CLOCKS_PER_SEC) << endl;

    delete (queue);
    cout << "\nQueue successfully destroyed\n" << endl;

    return EXIT_SUCCESS;
}

void test() {
    PriorityQueue<int> pq;

    cout << "Noch kein Element" << endl;
    cout << "pq.extractMin();" << endl;
    try {
        pq.extractMin();
    } catch (QueueException e) {
        cout << e.toString() << endl;
    }
    cout << "pq.isEmpty(): " << pq.isEmpty() << endl;
    pq.printEntries();

    cout << "\nnachdem ein element eingefuegt worden ist:" << endl;
    pq.insert(1, 12);
    pq.printEntries();

    cout << "\nMehr Elemente:" << endl;
    pq.insert(2, 5);
    pq.insert(3, 400);
    pq.insert(4, 21);
    pq.insert(5, 33);
    pq.printEntries();

    cout << "\npq.decreaseKey(0, 0) auf nicht vorhandenen Wert 0:" << endl;
    try {
        pq.decreaseKey(0, 0);
    } catch (QueueException e) {
        cout << e.toString() << endl;
    }

    cout << "\nnach extractMin:" << endl;
    pq.extractMin();
    pq.printEntries();

    cout << "\nPrio von 4 auf 2 setzen:" << endl;
    pq.decreaseKey(4, 2);
    pq.printEntries();

    cout << "\n1 entfernen" << endl;
    pq.remove(1);
    pq.printEntries();
}

void testTime() {
    PriorityQueue<int> *queue = new PriorityQueue<int>();
    clock_t tic, toc;

    /**
     * TIME MEASURING
     */
    cout << "\nMeasuring time for function pqueue_insert() ..." << endl;
    tic = clock();
    for (int i = 0; i < MAX; ++i) {
        queue->insert(rand() % 1000, rand() % 100);
    }
    toc = clock();
    cout << "Insertion time: " << ((float) (toc - tic) / CLOCKS_PER_SEC) << endl;
//    queue->printQueue();

    cout << "\nMeasuring time for function pqueue_extractMin() ..." << endl;
    tic = clock();
    for (int i = 0; i < MAX; ++i) {
        queue->extractMin();
    }
    toc = clock();
    cout << "Extract time: " << ((float) (toc - tic) / CLOCKS_PER_SEC) << endl;

    delete (queue);
    cout << "\nQueue successfully destroyed\n" << endl;
}

int main() {
//    testKai();
    test();
//    testTime();

    return 0;
}