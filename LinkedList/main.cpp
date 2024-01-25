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
        cout<<endl;
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
    void removeMidNode(Node* H){
        Node* DeleteIt=H->next;
        H->next=H->next->next;
        delete DeleteIt;
    }
    void move_back(int key){
        int limit=length+1;
        Node *tmp=Head;
        while (tmp->next!= nullptr&&limit--){
            if (tmp->next->data==key){
                insert(key);
                removeMidNode(tmp);
            }else
                tmp=tmp->next;
        }

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
                    ++length;
                    return;
                }
                tmp=tmp->next;
            }
            Tail->next=new Node(val);
            Tail->next->next= nullptr;
            Tail=Tail->next;
            ++length;
        }
    }
    void swapHeadandTail(){
        Node* prevTail=Head;
        while (prevTail->next!=Tail){
            prevTail=prevTail->next;
        }
        Node* HeNT=Head->next;
        Head->next= nullptr;
        prevTail->next=Head;
        Tail->next=HeNT;
        swap(Head,Tail);
    }
    void left_rotate(int k){
        k%=length;
        while (k--){

        }

    }

    void remove_duplicates(){
        for (Node* tmp1=Head;tmp1!= nullptr;tmp1=tmp1->next) {
            for (Node* tmp2=tmp1->next,*tmp2Back=tmp1;tmp2!= nullptr;) {
                if (tmp1->data==tmp2->data){
                    if (Tail==tmp2){
                        Tail=tmp2Back;
                    }
                    tmp2Back->next=tmp2->next;
                    delete tmp2;
                    tmp2=tmp2Back->next;

                }else{
                    tmp2=tmp2->next,tmp2Back=tmp2Back->next;
                }
            }
        }

    }
    void removeLastOccurnce(int key){
        Node* tmp=Head;
        Node* tmpPrev= nullptr;
        Node* Nkey{nullptr},*prevNkey{nullptr};
        while (tmp!= nullptr){
            if (tmp->data==key){
                Nkey=tmp;
                prevNkey=tmpPrev;
            }
            tmpPrev=tmp;
            tmp=tmp->next;
        }
        if (Nkey!= nullptr){
            if (Nkey==Head)
                pop_front(),--length;
            else if (Nkey==Tail)
                pop_back(),--length;
            else{
                prevNkey->next=Nkey->next,--length;
                delete Nkey;
            }
        }

    }
    int getMaxRec(Node* tmp){
        if (tmp== nullptr)
            return 0;
        return max(tmp->data, getMaxRec(tmp->next));
    }
    int getMaxRec(){
        return getMaxRec(Head);
    }
    void erase_th(int poss){
        if (poss==0){
            --length;
            this->pop_front();
            return;
        }else if (poss==length){
            --length;
            this->pop_back();
            return;
        }
        Node *tm=Head,*tmback=Head;
        int cnt{0};
        while (tm!= nullptr){
            if (cnt==poss){
                --length;
                Node* tmp=tm->next;
                delete tm;
                tmback->next=tmp;
                return;
            }
            ++cnt,tmback=tm,tm=tm->next;
        }

    }
    void arrangeOddEvenPoss(){
        insert(Head->data);
        pop_front();
        int times=(length/2)-1;
        for (Node* tmp=Head;tmp!= nullptr&&times--;tmp=tmp->next){
            insert(tmp->next->data);
            removeMidNode(tmp);
        }

    }
    linkedList()=default;
    linkedList& operator=(const linkedList& )=delete;
    linkedList(const linkedList& )=delete;
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
    sos.insert_sort(2);
    sos.insert_sort(3);
    sos.insert_sort(3);
    sos.insert_sort(5);
    sos.insert_sort(5);
    sos.insert_sort(3);
    sos.insert_sort(1);
    sos.insert_sort(1);
    sos.insert_sort(2);
    sos.insert_sort(6);
//    sos.swapHeadandTail();
//    sos.remove_duplicates();
//    sos.removeLastOccurnce(2);
    cout<<sos.Get_length()<<endl;
    sos.move_back(3);
    cout<<sos.getMaxRec()<<endl;
    sos.print();

    linkedList mostafa;
    for (int i = 1; i <=10 ; ++i) {
        mostafa.insert(i);
    }
    mostafa.print();
    mostafa.arrangeOddEvenPoss();
    mostafa.print();

    return 0;
}
