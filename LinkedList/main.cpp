#include <iostream>
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
    ~linkedList(){
        Node* tm=Head->next;
        while (Head!= nullptr){
            delete Head;
            Head=tm;
            if (tm!= nullptr)
            tm=tm->next;
        }
    }
};


int main() {
    linkedList mo;
    for (int i = 1; i <= 5; ++i) {
        mo.insert(i);
    }
    mo.print();
    cout<<flush;

    return 0;
}
