#include <iostream>
using namespace std;
struct Node{
    int data{};
    Node* next{nullptr};
    Node* prev{nullptr};
    Node(int data):data(data){}
    void set(Node* next,Node* prev){
        this->next=next;
        this->prev=prev;
    }
};
class linkedList{
    friend ostream& operator<<(ostream& os,const linkedList& li);
        private:
    Node* Head= nullptr;
    Node* Tail= nullptr;
    int length{0};
public:
    ///============insertion============
    void linkNode(Node* first,Node* second){
        if (first)
            first->next=second;
        if (second)
            second->prev=first;
    }
    void insert_end(int val){
        ++length;
        Node* item=new Node(val);
        if (!Head){
            Head=Tail=item;
        }else{
            linkNode(Tail,item);
            Tail=item;
        }
    }
    void insert_front(int val){
        ++length;
        Node* item=new Node(val);
        if (!Head){
            Head=Tail=item;
        }else{
            linkNode(item,Head);
            Head=item;
        }
    }
    void insert_sorted(int val){
        if (!Head)
            insert_end(val);
        else{
            if (Head->data>val) {
                insert_front(val);
                return;
            }
            Node* item=new Node(val);
            for (Node* tmp=Head;tmp!= Tail;tmp=tmp->next) {
                if (tmp->data<=val&&tmp->next->data>=val){
                    Node* tmpNxt=tmp->next;
                    linkNode(tmp,item);
                    linkNode(item,tmpNxt);
                    ++length;
                    return;
                }
            }
            insert_end(val);
        }
    }
    ///============insertion============
    ///============deletion============
    void delete_Node(Node* tmp){
        linkNode(tmp->prev,tmp->next);
        delete tmp;
    }
    void delete_front(){
        if (Head){
            Node* HeadNext=Head->next;
            delete_Node(Head);
            Head=HeadNext;
        }
    }
    void delete_back(){
        if (Tail){
            Node* TailBack=Tail->prev;
            delete_Node(Tail);
            Tail=TailBack;
        }
    }
    ///============deletion============
    ///============Homework 1============
    void delete_all_Node_wiht_key(int key){

        for (Node* tmp=Head;tmp!= nullptr;){
            if (tmp->data==key){
                if (tmp==Head) {
                    Node* tmpNext=tmp->next;
                    delete_front(), --length;
                    tmp=tmpNext;
                }
                else if (tmp==Tail) {
                    Node* tmpPrev=tmp->prev;
                    delete_back(), --length;
                    tmp= tmpPrev;
                }
                else {
                    Node* tmpPrev=tmp->prev;
                    linkNode(tmp->prev,tmp->next);
                    delete_Node(tmp), --length;
                    tmp=tmpPrev;
                }
            }else
                tmp=tmp->next;
        }
    }
    void delete_even_poss(bool isOdd= false){
        bool isTurn{isOdd};
        for (Node* tmp=Head;tmp!= nullptr;){
            if (isTurn){
                if (tmp==Head) {
                    Node* tmpNext=tmp->next;
                    delete_front(), --length;
                    tmp=tmpNext;
                }
                else if (tmp==Tail) {
                    Node* tmpPrev=tmp->next;
                    delete_back(), --length;
                    tmp= tmpPrev;
                }
                else {
                    Node* tmpPrev=tmp->next;
                    linkNode(tmp->prev,tmp->next);
                    delete_Node(tmp), --length;
                    tmp=tmpPrev;
                }
            }else
                tmp=tmp->next;
//            cout<<*this;
            isTurn=!isTurn;
        }
    }
    bool is_Palindrome(){
        Node* TmpH=Head,*TmpT=Tail;
        while (TmpH!=TmpT){
            if (TmpH->data!=TmpT->data)
                return false;
            TmpH=TmpH->next,TmpT=TmpT->prev;
        }
        return true;
    }

    ///============Homework 1============

    ///============Homework 2============
    Node* find_middle(){
        Node* l=Head,*r=Tail;
        while (l!=r){

            l=l->next;
            if (l==r)
                return l;
            r=r->prev;

        }
        return l;
    }
    void swapNode(Node* N1,Node* N2){
        if (N1->next==N2||N2->next==N1){
            Node* NNxx=N2->next;
            Node* NPrr=N1->prev;

            NNxx->prev=N1;
            N1->next=NNxx;
            N1->prev=N2;
            N2->next=N1;
            NPrr->next=N2;
            N2->prev=NPrr;
        }else if (N1==Head||N2==Tail){
            Node* N1Nxt=N1->next;
            Node* N2Prv=N2->prev;

            N1Nxt->prev=N2;
            N2->next=N1Nxt;
            N2->prev= nullptr;
            N2Prv->next=N1;

            N1->next= nullptr;
            N1->prev=N2Prv;
            Head=N2,Tail=N1;
//            swap(Head,Tail);
        }else{
            Node *N1Prv = N1->prev;
            Node *N1Nxt = N1->next;

            Node *N2Prv = N2->prev;
            Node *N2Nxt = N2->next;

            N1Prv->next = N2;
            N2->prev = N1Prv;
            N2->next = N1Nxt;
            N1Nxt->prev = N2;

            N2Prv->next = N1;
            N1->prev = N2Prv;
            N1->next = N2Nxt;
            N2Nxt->prev = N1;
        }

    }
    void swapFB(int nth){
        int nthC{nth};
        Node* tmp1=Head,*tmp2=Tail;
        while (nthC--){
            tmp1=tmp1->next;
            tmp2=tmp2->prev;
        }

        swapNode(tmp1,tmp2);

    }
    void mergList(const linkedList& source){
        Node* tmp1=Head;
        Node* tmp2=source.Head;
        while (tmp1||tmp2){
            if (tmp1&&tmp2){
                if (tmp1->data<=tmp2->data){
                    tmp1=tmp1->next;
                    continue;
                }else{
                    Node* tmp2Nx=tmp2->next;
                    if (tmp1==Head){
                        linkNode(nullptr,tmp2);
                        linkNode(tmp2,Head);
                        Head=tmp2;
                    }else{
                        linkNode(tmp1->prev,tmp2);
                        linkNode(tmp2,tmp1);
                    }
                    tmp2=tmp2Nx;
//                    tmp1=tmp1->next;
                }
            }else if (tmp1){
                tmp1=tmp1->next;
            }else if (tmp2){
                linkNode(Tail,tmp2);
                Tail=tmp2;
                tmp2->next= nullptr;
            }
        }

    }

    ///============Homework 2============

};
ostream& operator<<(ostream& os,const linkedList& li){
    for (Node* tmp=li.Head;tmp!= nullptr;tmp=tmp->next) {
        os<<tmp->data<<" ";
    }os<<"\n";
    return os;
}
int main() {
    linkedList mos;
//    mos.insert_sorted(10);
//    mos.insert_sorted(2);
//    mos.insert_sorted(3);
//    mos.insert_sorted(7);
//    mos.insert_sorted(9);
//    mos.insert_sorted(1);
//    mos.insert_sorted(0);
//    mos.insert_sorted(0);
//    mos.insert_sorted(0);
//    mos.delete_all_Node_wiht_key(0);

//mos.insert_sorted(1);
//mos.insert_sorted(2);
//mos.insert_sorted(3);
//mos.insert_sorted(4);
//mos.insert_sorted(10);
//    mos.delete_even_poss();
//    mos.delete_even_poss(true);

    mos.insert_end(1);
    mos.insert_end(2);
    mos.insert_end(3);
    mos.insert_end(4);
    mos.insert_end(5);
    mos.insert_end(6);
//cout<<mos.is_Palindrome();
//    cout<<mos.find_middle()->data;
//
//    cout<<mos;
//    mos.swapFB(0);
//    mos.swapFB(1);
//    cout<<mos;

    linkedList l1,l2;
    l1.insert_end(1);
    l1.insert_end(2);
    l1.insert_end(4);
    l1.insert_end(6);

    l2.insert_end(3);
    l2.insert_end(5);
    l1.mergList(l2);
    cout<<l1;
    return 0;
}
