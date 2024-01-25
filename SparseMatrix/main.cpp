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
    Node* find_poss(int poss){
        for (Node* tmp=Head;tmp!= nullptr;tmp=tmp->next){
            if (tmp->poss==poss){ return tmp;}
        }
        return nullptr;
    }
public:
    int length{0};
    SparseArray(int lenght=0):length(lenght){}


    void set_value(int data,int poss){
        length= max(length,poss+1);
        if (Head== nullptr||Head->poss>poss){
            insertFront(new Node(data,poss));
            return;
        }else if (Tail->poss==poss){
            Tail->data=data;
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
        while (lastPrint<=length)
            cout<<0<<" ",++lastPrint;

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
    int& operator[](int poss){
        if (poss>=length)
            length=poss+1;

        Node* tmp= find_poss(poss);
        if (tmp== nullptr){
            set_value(0,poss);
            tmp= find_poss(poss);
        }
        return tmp->data;
    }
    ~SparseArray(){
        Node* delNode= nullptr;
        while (Head!= nullptr){
             delNode=Head;
             Head=Head->next;
             delete delNode;
        }
    }
};
class SparseMatrix{
private:
    struct Node{
        Node* next= nullptr;
        Node* prev= nullptr;
        int possX;
        SparseArray data;
        Node(int possX):possX(possX), data(){}
        Node(int possX,int possY,int dt,int lengthY=1):possX(possX),data(lengthY){
            data.set_value(dt,possY);
        }

    };
    Node* Head= nullptr;
    Node* Tail= nullptr;

    void insertFront(Node* nd){
        if (Head == nullptr){
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
    Node* find_poss(int possX){
        for (Node* tmp=Head;tmp!= nullptr;tmp=tmp->next){
            if (tmp->possX==possX){ return tmp;}
        }
        return nullptr;
    }

public:
    int lengthOfNodes;
    SparseMatrix(int lenght=0):lengthOfNodes{lenght}{}

    void set_value(int possX,int possY=-1,int val=-1){
        lengthOfNodes= max(lengthOfNodes,max(possX+1,possY+1));

        if (Head == nullptr){
            (possY==-1)?insertFront(new Node(possX)):insertFront(new Node(possX,possY,val));
            return;
        }else if (Head->possX==possX){
            Head->data.set_value(val,possY);
            return;
        }

            for (Node* tmp=Head;tmp->next!= nullptr;tmp=tmp->next){
                if (tmp->possX==possX){
                    tmp->data.set_value(val,possY);
                    return;
                }else if (tmp->possX<possX&&tmp->next->possX>possX){
                    (possY==-1)?insertAfterNode(tmp, new Node(possX)):insertAfterNode(tmp, new Node(possX, possY, val));
                    return;
                }
            }
        if(possY==-1)
            insertBack(new Node(possX));
        else
            insertBack(new Node(possX,possY,val));

    }
    void print(){
        Node* tmp=Head;
        int lastPrint{0};
        while (tmp!= nullptr){
            tmp->data.length=lengthOfNodes;
            while (lastPrint<tmp->possX) {
                for (int i = 0; i <= lengthOfNodes; ++i) {cout<<0<<" ";}
                cout<<endl;
                ++lastPrint;
            }
            tmp->data.print();
            lastPrint=tmp->possX+1;
            tmp=tmp->next;
            cout<<flush;
        }
        while (lastPrint<lengthOfNodes) {
            for (int i = 0; i <= lengthOfNodes; ++i) {cout<<0<<" ";}
            cout<<endl;
             ++lastPrint;
        }

        cout<<endl;
    }
    void printNoneZero(){
        Node* tmp=Head;
        while (tmp!= nullptr){
            tmp->data.printNonZero();
            tmp=tmp->next;
        }
    }
    SparseArray& operator[](int possX){
        Node* tmp=find_poss(possX);
        if (tmp== nullptr)
            set_value(possX);

        tmp=find_poss(possX);
        return tmp->data;
    }
    ~SparseMatrix(){
        Node* rmPtr= nullptr;
        while (Head!= nullptr){
            rmPtr=Head;
            Head=Head->next;
            delete rmPtr;
        }
    }

};
int main() {
    SparseMatrix most;
    most.set_value(0,0,1);
    most.set_value(0,10,2);
    most.set_value(0,10,3);
    most.set_value(5,10,4);
    most.set_value(4,10,5);
    most.print();
//    cout<<"============\n";
//    most[0][0]=155;
//    most.print();
//    cout<<"============\n";
//    most[15][10]=159;
//    most.print();
    return 0;
}
