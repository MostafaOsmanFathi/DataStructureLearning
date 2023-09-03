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
public:
   Vector(int size);
    ~Vector();
    void push_back(int val);
};


#endif //VECTOR_VECTOR_H
