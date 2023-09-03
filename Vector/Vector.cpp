//
// Created by mostafa on 9/3/23.
//

#include "Vector.h"
Vector::Vector(int size):size(size){
    if (size<1)size=1;
    capacity=size;
    data=new int[size]{0};
}
Vector::~Vector() {
    delete [] data;
}

void Vector::expand_capacity(){
    capacity*=2;
    int *data2=new int [capacity];
    for (int i = 0; i <size ; ++i) {
        data2[i]=data[i];
    }
    std::swap(data2,data);
    delete[] data2;
}
void Vector::push_back(int val) {
    if (size==capacity)
        expand_capacity();
    data[size++]=val;
}

//void Vector::push_back(int val){ ///not efficant Way
//int  *data2=new int [size+1];
//for (int i = 0; i <size; ++i) {
//data2[i]=data[i];
//}
//data2[size++]=val;
//std::swap(data2,data);
//delete [] data2;
//}
