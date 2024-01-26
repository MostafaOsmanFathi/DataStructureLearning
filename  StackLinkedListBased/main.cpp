#include <iostream>
#include <cassert>
using namespace std;
class Stack{
private:
    struct  Node{
        Node* next= nullptr;
        int data;
        Node(int data):data(data){

        }
    };
    int length{0};
    Node* Top= nullptr;
public:
    void push(int val){
        Node* nd=new Node(val);
        if (Top== nullptr){
            Top=nd;
        }else{
           nd->next=Top;
           Top=nd;
        }
        ++length;
    }
    int pop(){
        assert(Top!= nullptr);
       int tmp=Top->data;
        Node* rmNode=Top;
        Top=Top->next;
        delete rmNode;
        return tmp;
    }
    int peek(){
        assert(Top!= nullptr);
        return Top->data;
    }
    void insertBottom(int& val){
        if (isEmpty()){
            push(val);
            return;
        }
        int tmp=pop();
        insertBottom(val);
        push(tmp);
    }
    bool isEmpty(){return Top== nullptr;}
    void reverse(){
        if (isEmpty()){
            return;
        }

        int tmp=pop();
        reverse();
        insertBottom(tmp);
    }
    ~Stack(){
        while (!isEmpty())
                pop();
    }
};


int main() {
    Stack most;
    for (int i = 0; i <10 ; ++i) {
        most.push(i);
    }
    most.reverse();
    while (!most.isEmpty())
        cout<<most.pop()<<endl;
    return 0;
}