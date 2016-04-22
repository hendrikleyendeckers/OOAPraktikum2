#ifndef OOAPRAKTIKUM2_QUEUEEXCEPTION_H
#define OOAPRAKTIKUM2_QUEUEEXCEPTION_H

#include <string>
using namespace std;

class QueueException {
private:
    string error;
public:
    QueueException(string error);
    string toString();
    string getError();
};

QueueException::QueueException(string error) {
    this->error = error;
}

string QueueException::toString() {
    return this->error;
}

string QueueException::getError() {
    return "ERROR: " + this->error;
}

#endif //OOAPRAKTIKUM2_QUEUEEXCEPTION_H
