#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* Next;
    Node(int data):data(data){}
};
Node* findNode(int val,Node* Head){
    while (Head!= nullptr){
        if (Head->data==val)
            return Head;
        Head=Head->Next;
    }
    return nullptr;
}
int main() {
    Node val1(1);
    Node val2(2);
    Node val3(3);
    Node val4(4);
    val1.Next=&val2;
    val2.Next=&val3;
    val3.Next=&val4;
    val4.Next= nullptr;
    cout<<"\n======================================\n";
    Node* tmp=&val1;
    while (tmp!= nullptr){
        cout<<tmp->data<<" ";
        tmp=tmp->Next;
    }
    cout<<"\n======================================\n";

    cout<<findNode(4,&val1)->data<<endl;

    cout<<"\n======================================\n";
    for (Node *Head=&val1; Head!= nullptr ; Head=Head->Next) {
        cout<<Head->data<<" ";
    }

    cout<<"\n======================================\n";


    return 0;
}
