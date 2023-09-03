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
   Vector(int size):size(size){
       if (size<1)size=1;
       data=new int[size]{0};
   }
~Vector(){
       delete [] data;
   }

   void push_back(int val){ ///not efficant Way 
    int  *data2=new int [size+1];
    for (int i = 0; i <size; ++i) {
        data2[i]=data[i];
    }
    data2[size]=val;
    std::swap(data2,data);
    delete [] data2;
   }

};


#endif //VECTOR_VECTOR_H
