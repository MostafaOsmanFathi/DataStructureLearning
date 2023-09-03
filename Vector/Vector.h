//
// Created by mostafa on 9/3/23.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <iostream>
class Vector {
private:
    int *data;
    int size;
    int capacity{0};
public:
   explicit Vector(int size=1);
    ~Vector();
    void expand_capacity();
    void push_back(int val);
};


#endif //VECTOR_VECTOR_H
