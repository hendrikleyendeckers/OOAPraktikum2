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

#endif //OOAPRAKTIKUM2_QUEUEEXCEPTION_H
