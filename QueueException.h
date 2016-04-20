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
};

QueueException::QueueException(string error) {
    this->error = error;
}

string QueueException::toString() {
    return this->error;
}


#endif //OOAPRAKTIKUM2_QUEUEEXCEPTION_H
