#include <iostream>
using namespace std;
class SparseArray{
private:
    struct Node{
        Node* next= nullptr;
        Node* prev= nullptr;
        int data,poss;
        Node(int data,int poss):data(data),poss(poss){

        }
    };
    Node* Head= nullptr;
    Node* Tail= nullptr;

    void insertFront(Node* nd){
        if (Head== nullptr){
            Head=Tail=nd;
            return;
        }
        nd->next=Head;
        Head->prev=nd;
        Head=nd;
    }
    void insertBack(Node* nd){
        if (Head== nullptr){
            Head=Tail=nd;
            return;
        }
        Tail->next=nd;
        nd->prev=Tail;
        Tail=nd;
    }
    void insertAfterNode(Node* tmp,Node* nd){
        if (tmp->next== nullptr){
            insertBack(nd);
        }else{
            nd->next=tmp->next;
            tmp->next->prev=nd;
            nd->prev=tmp;
            tmp->next=nd;
        }
    }
public:
    int length{0};
    SparseArray(int lenght):length(lenght){}

    Node* find_poss(int poss){
        for (Node* tmp=Head;tmp!= nullptr;tmp=tmp->next){
            if (tmp->poss==poss){ return tmp;}
        }
        return nullptr;
    }
    void set_value(int data,int poss){
        length= max(length,poss+1);
        if (Head== nullptr||Head->poss>poss){
            insertFront(new Node(data,poss));
            return;
        }
            for (Node* tmp=Head;tmp->next!= nullptr;tmp=tmp->next){
                if (tmp->poss==poss){
                    tmp->data=data;
                    return;
                }else if (tmp->poss<poss&&tmp->next->poss>poss){
                    insertAfterNode(tmp,new Node(poss,data));
                    return;
                }
            }
        insertBack(new Node(data,poss));
    }
    void printNonZero(){
        for (Node* tmp=Head;tmp!= nullptr;tmp=tmp->next){
            cout<<tmp->data<<" ";
        }
        cout<<endl;
    }
    void print(){
        int lastPrint{0};
        for (Node* tmp=Head;tmp!= nullptr;tmp=tmp->next){
            while (lastPrint<tmp->poss)
                cout<<0<<" ",++lastPrint;
            cout<<tmp->data<<" ";
            lastPrint=tmp->poss+1;

        }
        cout<<endl;
    }

};


int main() {
    SparseArray most{10};
    most.set_value(1,1);
    most.set_value(5,3);
    most.set_value(10,10);
    most.set_value(2,2);
    most.printNonZero();
    most.print();
    return 0;
}
