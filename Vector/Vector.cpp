//
// Created by mostafa on 9/3/23.
//

#include "Vector.h"
Vector::Vector(int size):size(size){
    if (size<1)size=1;
    data=new int[size]{0};
}
Vector::~Vector() {
    delete [] data;
}

void Vector::push_back(int val){ ///not efficant Way
int  *data2=new int [size+1];
for (int i = 0; i <size; ++i) {
data2[i]=data[i];
}
data2[size++]=val;
std::swap(data2,data);
delete [] data2;
}
