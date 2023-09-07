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
    void pop_front(){
        --length;
        Node *tmp=Head;
        Head=Head->next;
        delete tmp;
    }
    void pop_back(){
      --length;
      Node* tmp=Head;
        while (tmp->next!= Tail){
            tmp=tmp->next;
        }
        delete Tail;
        Tail=tmp;
        Tail->next= nullptr;
    }
    void delete_Node_with_key(int key){
        Node* tmp=Head;
        if (Head->data==key){
            pop_front();
            return;
        }else if (Tail->data==key){
            pop_back();
            return;
        }
        while (tmp->next!= nullptr){
            if (tmp->next->data==key){
                Node* tmpCur=tmp->next->next;
                delete tmp->next;
                tmp->next=tmpCur;
                return;
            }
            tmp=tmp->next;
        }
        assert(false);
    }
    void swap_pairs(){
        Node* tmp=Head;
        while ((tmp!= nullptr)&&tmp->next!= nullptr){
            swap(tmp->data,tmp->next->data);
            tmp=tmp->next->next;
        }
    }
    void reverse(){
        Node* pervNode= nullptr;
        Node* curN=Head;
        Node* NextNode=Head->next;
        int cur=0;
        while (curN!=nullptr){
            curN->next=pervNode;
            pervNode=curN;
            curN=NextNode;
            if (NextNode!= nullptr)
            NextNode=NextNode->next;
            ++cur;
        }
        swap(Head,Tail);
    }
    void delete_even_poss(){
        bool isEven= false;
        Node* tmp=Head;
        Node* tmpBack= nullptr;
        while (tmp!= nullptr){
            if (isEven){
                --length;
                if (tmp==Tail){
                    pop_back();
                    break;
                }
                tmpBack->next=tmp->next;
                delete tmp;
                tmp=tmpBack;
            }
            tmpBack=tmp,tmp=tmp->next;
            isEven=!isEven;
        }

    }
    void insert_sort(int val){
        if (length==0){
            insert(val);
        }else{
            if (Head->data>val) {
                insertFront(val);
                return;
            }
            Node* tmp=Head;
            while (tmp->next!= nullptr){
                if (tmp->data<=val&&tmp->next->data>=val){
                    Node* tmpNext=tmp->next;
                    tmp->next=new Node(val);
                    tmp->next->next=tmpNext;
                    return;
                }
                tmp=tmp->next;
            }
            Tail->next=new Node(val);
            Tail->next->next= nullptr;
            Tail=Tail->next;
        }
    }
    void erase_th(int poss){
        if (poss==0){
            this->pop_front();
            return;
        }else if (poss==length){
            this->pop_back();
            return;
        }
        Node *tm=Head,*tmback=Head;
        int cnt{0};
        while (tm!= nullptr){
            if (cnt==poss){
                Node* tmp=tm->next;
                delete tm;
                tmback->next=tmp;
                return;
            }
            ++cnt,tmback=tm,tm=tm->next;
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
//    mo.erase_th(mo.Get_length());
//    mo.delete_Node_with_key(40);
//    mo.swap_pairs();
//    mo.reverse();

//    cout<<mo.Get_length()<<endl;
//    mo.print();
//    cout<<endl;
//    mo.delete_even_poss();
//    cout<<mo.Get_length()<<endl;
//    mo.print();
    linkedList sos;
    sos.insert_sort(5);
    sos.insert_sort(4);
    sos.insert_sort(1);
    sos.insert_sort(0);
    sos.insert_sort(2);
    sos.print();

    return 0;
}
