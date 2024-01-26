#include <iostream>
#include <assert.h>
using namespace std;
class Stack{
private:
    int *arr= nullptr;
    int length;
    int top;

    void AllocateNewSpace(){
        int* tmpArr=new int[length*2];
        for (int i = 0; i < length; ++i) {tmpArr[i]=arr[i];}
        delete [] arr;
        arr=tmpArr;
        tmpArr= nullptr;
        length*=2;
    }
public:
    bool isEmpty(){return top==-1;}
    bool isFull(){return top==length-1;}

    Stack(int length):length(length),arr(new int[length]){}
    Stack():arr(new int [1]),top(-1),length(0){}
    bool push(int val){
        if (top+1==length){AllocateNewSpace();}
        arr[++top]=val;
        return true;
    }
    int pop(){
        assert(!isEmpty());
        return arr[top--];
    }
    int& peek(){
        assert(!isEmpty());
        return arr[top];
    }

    ~Stack(){
        delete[]arr;
    }
};

int main() {
    Stack mos;
    for (int i = 0; i < 5; ++i) {
        mos.push(i);
    }
    while (!mos.isEmpty())
        cout<<mos.pop();

    return 0;
}
