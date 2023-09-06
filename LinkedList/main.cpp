#include <iostream>
#include <assert.h>
using namespace std;
struct Node{
    int data;
    Node* next{nullptr};
    Node(int data):data(data){}
};
class linkedList{
private:
    Node* Head{nullptr};
    Node* Tail{nullptr};
    int length{0};
public:
    void print(){
        Node* tmp=Head;
        while (tmp!= nullptr){
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
    }
    void insert(int val){
        if (length==0){
            Head=new Node(val);
            Tail=Head;
        }else{
         Tail->next=new Node(val);
         Tail=Tail->next;
        }
        ++length;
    }
    void insertFront(int val){
        ++length;
        Node* tmp=new Node(val);
        Node* tmp2=Head;
        Head=tmp;
        Head->next=tmp2;
    }
    void deleteFront(){
        --length;
        Node* tmp=Head;
        Head=Head->next;
        delete tmp;
    }
    int  get_nth(int n){
        if (n>length){return -1;}
        --n;
        Node* tmp=Head;
        while (n--){
            tmp=tmp->next;
        }
        return tmp->data;
    }
    int get_nthBack(int n){
        return get_nth(length-n);
    }
    Node* search(int val){
        for (Node* tmp=Head;tmp!= nullptr;tmp=tmp->next) {
            if (tmp->data==val)
                return tmp;
        }
        return nullptr;
    }
    Node* searchAndShiftL(int key){
        Node* tmp=Head;
        Node* tmpBack=Head;
        while (tmp!= nullptr){
            if (tmp->data==key){
                if (tmp!=Head){
                    swap(tmp->data,tmpBack->data);
                }
                return  tmpBack;
            }
            tmpBack=tmp;
            tmp=tmp->next;
        }
        return nullptr;
    }
    void checkVerfied(){
        if (length==0){
            assert(Head== nullptr&&Tail== nullptr);
        }else if (length==1){
            assert(Head==Tail);
        }else{
            assert(Head!=Tail);
        }
    }
    bool is_SameData(const linkedList& source){
        if (source.length==length){
            Node* Tmp{Head};
            Node* Tmp2{source.Head};
            while (Tmp!= nullptr){
                if (Tmp->data!=Tmp2->data)
                    return false;
                Tmp=Tmp->next,Tmp2=Tmp2->next;
            }

        }else return false;

    }
    int Get_length(){return length;}
    ~linkedList(){
        Node* tm=Head->next;
        while (Head!= nullptr){
            delete Head;
            Head=tm;
            if (tm!= nullptr)
            tm=tm->next;
        }
    }
    linkedList& operator=(const linkedList& )=delete;
};


int main() {
    linkedList mo;
    for (int i = 1; i <= 5; ++i) {
        mo.insert(i);
    }
    for (int i = 10; i <=50 ; i+=10) {
        mo.insertFront(i);
    }
//    cout<<mo.Get_length();
    mo.deleteFront();
    mo.deleteFront();
    cout<<mo.get_nthBack(5)<<endl;
    mo.print();
    return 0;
}
