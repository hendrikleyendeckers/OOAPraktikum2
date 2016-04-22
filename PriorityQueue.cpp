//
// Created by hendy on 19.04.2016.
//

#include "PriorityQueue.h"


QueueException::QueueException(string error) {
    this->error = error;
}

string QueueException::toString() {
    return this->error;
}