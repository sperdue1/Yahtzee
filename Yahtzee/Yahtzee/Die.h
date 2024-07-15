#pragma once
#ifndef DIE_H
#define DIE_H

class Die {
private:
    int faceValue;
public:
    Die();
    int roll();
    int getFaceValue();

};

#endif

