#ifndef OOAPRAKTIKUM2_PRIORITYQUEUE_H
#define OOAPRAKTIKUM2_PRIORITYQUEUE_H

#include <string>
#include <iostream>
#include "QueueException.h"

template<typename T>
class PriorityQueue {

protected:
    struct PriorityQueueEntry_t {
        T value;
        float priority;
    };
    PriorityQueueEntry_t *priorityQueueEntry;
    int _size;
    int _last;

public:
    PriorityQueue();
    ~PriorityQueue();
    void insert(T value, float priority);
    T extractMin(void);
    void decreaseKey(T value, float priority);
    void remove(T value);
    bool isEmpty();
    void printEntries();
    void printQueue();
};

template<typename T>
PriorityQueue<T>::PriorityQueue() {
    priorityQueueEntry = NULL;
    _size = 0;
    _last = 0;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue<T>() {
//    for (int i = 0; i < this->_size; i++) {
//        delete priorityQueueEntry[i];
//    }
    delete[] priorityQueueEntry;
}

template<typename T>
void PriorityQueue<T>::insert(T value, float priority) {
    // TODO: Kann weg, wenn _last = 0, _size = 1
    if (this->isEmpty()) {
        this->priorityQueueEntry = new PriorityQueueEntry_t[2];
        this->priorityQueueEntry[0].priority = priority;
        this->priorityQueueEntry[0].value = value;

        this->_size = 2;
        this->_last = 0;
        return;
    }

    //verdoppeln wenn Speicher voll ist
    if (this->_last == (this->_size - 1)) {
        this->_size *= 2;

        //doppelten speicher anlegen
        PriorityQueueEntry_t *tmp;
        //doppelt so großes pointerArray allokieren
        tmp = new PriorityQueueEntry_t[this->_size];

        //vorhandene elemente übertragen auf neues array
        for (int i = 0; i <= this->_last; i++) {
            tmp[i] = this->priorityQueueEntry[i];
        }

        //altes array löschen
        delete[] this->priorityQueueEntry;
//        delete this->priorityQueueEntry;

        //auf neues array zeigen lassen
        this->priorityQueueEntry = tmp;
    }

    //sortieren und einfügen
    //falls letzter index.p kleiner als funktionsparameter p
    if (this->priorityQueueEntry[this->_last].priority >= priority) {
        this->priorityQueueEntry[this->_last + 1].priority = priority;
        this->priorityQueueEntry[this->_last + 1].value = value;
    }

    if (this->priorityQueueEntry[this->_last].priority < priority) {
        //läuft bis index 0 solange index.p > p
        for (int i = this->_last; i >= 0 && this->priorityQueueEntry[i].priority < priority; i--) {
            this->priorityQueueEntry[i + 1].priority = this->priorityQueueEntry[i].priority;
            this->priorityQueueEntry[i + 1].value = this->priorityQueueEntry[i].value;

            //falls nächstes element i-1 kleiner/gleich p ist, dann aktuelles element überschreiben
            if (i == 0 || this->priorityQueueEntry[i - 1].priority >= priority) {
                this->priorityQueueEntry[i].priority = priority;
                this->priorityQueueEntry[i].value = value;
            }
        }
    }

    // TODO: new search algorithm
//    if (this->priorityQueueEntry[this->_last]->priority < priority) {
        // Array immer in der mitte teilen
        // -> gucken ob linke oder recht hälfte größer
        //    => solange bis bis array größe = 2
//    }

    this->_last += 1;
}

template<typename T>
T PriorityQueue<T>::extractMin(void) {
    if (this->isEmpty()) {
        throw QueueException("No Elements found");
    }

    T tmp = this->priorityQueueEntry[this->_last].value;
    delete this->priorityQueueEntry[this->_last];

    this->_last -= 1;

    return tmp;
}

template<typename T>
void PriorityQueue<T>::decreaseKey(T value, float priority) {
    bool found = false;
    for (int i = 0; i < this->_last; i++) {
        if (this->priorityQueueEntry[i].value == value) {
            found = true;
            break;
        }
    }

    if ( ! found) {
        throw QueueException("Value was not found.");
    }

    this->remove(value);
    this->insert(value, priority);
}

template<typename T>
void PriorityQueue<T>::remove(T value) {
    for (int i = 0; i < this->_last; i++) {
        if (this->priorityQueueEntry[i]->value == value) {
            for (int j = i; j <= this->_last; j++) {
                this->priorityQueueEntry[j]->priority = this->priorityQueueEntry[j + 1]->priority;
                this->priorityQueueEntry[j]->value = this->priorityQueueEntry[j + 1]->value;
            }

            this->_last -= 1;
        }
    }

    // halbieren falls nur ein viertel voll (anzahl elemente kleiner this->size/4
    if ((this->_last + 1) < (this->_size / 4)) {
        this->_size /= 2;

        PriorityQueueEntry_t **tmp;
        // halb so großes pointerArray allokieren
        tmp = new PriorityQueueEntry_t *[this->_size];

        // vorhandene elemente übertragen auf neues array
        for (int i = 0; i <= this->_last; i++) {
            tmp[i] = this->priorityQueueEntry[i];
        }

        // altes array löschen
        delete(this->priorityQueueEntry);

        // auf neues array zeigen lassen
        this->priorityQueueEntry = tmp;
    }
}

template<typename T>
bool PriorityQueue<T>::isEmpty() {
    return this->_size == 0;
}

template<typename T>
void PriorityQueue<T>::printEntries() {
    if (this->_size == 0) {
        return;
    } else {
        for (int i = 0; i <= this->_last; i++) {
            cout << "Element " << i << ", ";
            cout << "Value " << this->priorityQueueEntry[i].value << ", ";
            cout << "Priority " << this->priorityQueueEntry[i].priority << endl;
        }
    }
    cout << endl;
}

template <typename T>
void PriorityQueue<T>::printQueue() {
    this->printEntries();
}



#endif //OOAPRAKTIKUM2_PRIORITYQUEUE_H
