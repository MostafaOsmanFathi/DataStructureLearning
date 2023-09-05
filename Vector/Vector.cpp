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
int& Vector::at(int poss){
    int npos=-1;
    if (poss>=0&&poss<size)return data[poss];
    else return npos;
}
void Vector::insert(int poss,int val){
    if (size==capacity)
        expand_capacity();
    ++size;
    for (int i = this->size-1; i >=poss ; --i) {
        data[i]=data[i-1];
    }
    data[poss]=val;

}
void Vector::right_rotation(int n){
    int *data2=new int [capacity];
    for (int i = 0; i < size; ++i) {
        data2[(i+n)%size]=data[i];
    }
    std::swap(data2,data);
    delete [] data2;
}
void Vector::left_rotation(int n){
    int *data2=new int [capacity];
    for (int i = 0; i < size; ++i) {
        int poss=((i-n)+size)%size;
        data2[poss]=data[i];
    }
    std::swap(data2,data);
    delete [] data2;
}

int Vector::pop(int poss){
    int tmp= this->at(poss);
    this->at(poss)=0;
    for (int i = poss; i <size ; ++i) {
        data[i]=data[i+1];
    }
    --size;
    return tmp;
}
int Vector::find(int key){
    for (int i = 0; i <size ; ++i) {
        if (data[i]==key)return i;
    }
    return -1;
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
