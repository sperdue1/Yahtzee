#include "Die.h"
#include <cstdlib>
#include <ctime>

Die::Die() : faceValue(0) {
    srand(time(0));
}

int Die::roll() {
    faceValue = rand() % 6 + 1;
    return faceValue;
}

int Die::getFaceValue() {
    return faceValue;
}
