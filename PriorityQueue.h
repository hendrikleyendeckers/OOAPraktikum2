#ifndef OOAPRAKTIKUM2_PRIORITYQUEUE_H
#define OOAPRAKTIKUM2_PRIORITYQUEUE_H

#include <string>
#include "QueueException.h"

template<typename T>
class PriorityQueue {

protected:
    struct PriorityQueueEntry_t {
        T value;
        float priority;
    };
    PriorityQueueEntry_t **priorityQueueEntry;
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
void PriorityQueue::insert(T value, float priority) {
    // TODO: Kann weg, wenn _last = -1, _size = 0
    if (this->isEmpty()) {
        this->priorityQueueEntry = new PriorityQueueEntry_t *[2];
        this->priorityQueueEntry[0] = new PriorityQueueEntry_t;
        this->priorityQueueEntry[0]->priority = priority;
        this->priorityQueueEntry[0]->value = value;
        // TODO: Kann weg?
        this->priorityQueueEntry[1] = new PriorityQueueEntry_t;

        this->_size = 2;
        this->_last = 0;
    }

    //verdoppeln wenn Speicher voll ist
    if (this->_last == (this->_size - 1)) {
        this->_size *= 2;

        //doppelten speicher anlegen
        PriorityQueueEntry_t **tmp;
        //doppelt so großes pointerArray allokieren
        tmp = new PriorityQueueEntry_t*[this->_size];

        //speicher reservieren für alle strukturen ab dem letzten
        // TODO: Kann weg?
        for (int i = (this->_last + 1); i < this->_size; i++) {
            tmp[i] = new PriorityQueueEntry_t;
        }

        //vorhandene elemente übertragen auf neues array
        for (int i = 0; i <= this->_last; i++) {
            tmp[i] = this->priorityQueueEntry[i];
        }

        //altes array löschen
        delete (this->priorityQueueEntry);

        //auf neues array zeigen lassen
        this->priorityQueueEntry = tmp;
    }

    //sortieren und einfügen
    //falls letzter index.p kleiner als funktionsparameter p
    if (this->priorityQueueEntry[this->_last]->priority >= priority) {
        this->priorityQueueEntry[this->_last + 1] = new PriorityQueueEntry_t;
        this->priorityQueueEntry[this->_last + 1]->priority = priority;
        this->priorityQueueEntry[this->_last + 1]->value = value;
    }

    if (this->priorityQueueEntry[this->_last]->priority < priority) {
        //läuft bis index 0 solange index.p > p
        for (int i = this->_last; i >= 0 && this->priorityQueueEntry[i]->priority < priority; i--) {
            this->priorityQueueEntry[i + 1] = this->priorityQueueEntry[i];

            //falls nächstes element i-1 kleiner/gleich p ist, dann aktuelles element überschreiben
            if (i == 0 || this->priorityQueueEntry[i - 1]->priority >= priority) {
                // TODO: Kann weg, da schon alle allokiert sind?
//                this->priorityQueueEntry[i] = new PriorityQueueEntry_t;
                this->priorityQueueEntry[i]->priority = priority;
                this->priorityQueueEntry[i]->value = value;
            }
        }
    }
    this->_last += 1;
}

template<typename T>
T PriorityQueue::extractMin(void) {
    if (this->isEmpty()) {
        throw QueueException("No Elements found");
    }

    T tmp = this->priorityQueueEntry[this->_last]->value;
    delete this->priorityQueueEntry[this->_last];

    this->_last -= 1;

    return tmp;
}

template<typename T>
void PriorityQueue::decreaseKey(T value, float priority) {
    this->remove(value);
    this->insert(value, priority);
}

template<typename T>
void PriorityQueue::remove(T value) {
    for (int i = 0; i < this->_last; i++) {
        if (this->priorityQueueEntry[i]->value == value) {
            for (int j = i; j <= this->_last; j++) {
                this->priorityQueueEntry[j] = this->priorityQueueEntry[j + 1];
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

        // TODO: Kann weg?
        for (int i = (this->_last + 1); i < this->_size; i++) {
            tmp[i] = new PriorityQueueEntry_t;
        }

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
bool PriorityQueue::isEmpty() {
    return this->_size == 0;
}


#endif //OOAPRAKTIKUM2_PRIORITYQUEUE_H
