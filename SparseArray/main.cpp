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
    void addSparseArray(const SparseArray& rhs){
        length= max(length,rhs.length);
        Node* tmp1=Head;
        for (Node* tmp=rhs.Head;tmp!= nullptr;tmp=tmp->next){
            while ((tmp1->next!= nullptr)&&tmp1->poss<tmp->poss){tmp1=tmp1->next;}
            if ((tmp1!= nullptr)&&tmp1->poss==tmp->poss){
                tmp1->data+=tmp->data;
            }else{
                insertAfterNode(tmp1,new Node(tmp->data,tmp->poss));
            }
        }
    }
    SparseArray& operator+=(const SparseArray& rhs){
        addSparseArray(rhs);
        return *this;
    }
};


int main() {
    SparseArray most{10};
    most.set_value(1,1);
    most.set_value(5,3);
    most.set_value(10,10);
    most.set_value(2,2);
    SparseArray moca{21};

    moca.set_value(100,1);
    moca.set_value(200,2);
    moca.set_value(300,3);
    moca.set_value(1000,10);
    moca.set_value(2000,20);

    most.addSparseArray(moca);
    most.printNonZero();
    most.print();

    most+=most;
    most.printNonZero();
    most.print();

    return 0;
}
