#include <iostream>
#include <cassert>
#include <stack>
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
    int& peek(){
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
int postfixEvaluation(string s){
    Stack st;
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s.at(i)))st.push(s.at(i)-'0');
        else{
            int x=st.pop();
            if (s.at(i)=='+'){
                st.peek()+=x;
            }else if (s.at(i)=='-'){
                st.peek()-=x;
            }else if (s.at(i)=='*'){
                st.peek()*=x;
            }else if (s.at(i)=='/'){
                st.peek()/=x;
            }
        }
    }
    return st.peek();
}
int infixEvaluation(string s){
    Stack st;
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s.at(i)))st.push(s.at(i)-'0');
        else{
            int x=s.at(i+1)-'0';
            if (s.at(i)=='+'){
                st.peek()+=x;
            }else if (s.at(i)=='-'){
                st.peek()-=x;
            }else if (s.at(i)=='*'){
                st.peek()*=x;
            }else if (s.at(i)=='/'){
                st.peek()/=x;
            }
            ++i;
        }
    }
    return st.peek();
}
int operatorPrecedence(char c){
    if (c=='-')return 1;
    else if (c=='+')return 2;
    else if (c=='/')return 3;
    else if (c=='*')return 4;
    return 10;
}
string convertInfixToPostfix(string s){
    string ans;
    stack<char>st;
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s.at(i)))ans.push_back(s.at(i));
        else{
            if (st.empty()||operatorPrecedence(st.top())<=operatorPrecedence(s.at(i)))st.push(s.at(i));
            else{
                    while (!st.empty())ans.push_back(st.top()),st.pop();
                    st.push(s.at(i));
            }
        }
    }
    while (!st.empty())ans.push_back(st.top()),st.pop();
    return ans;
}

int main() {
//    Stack most;
//    for (int i = 0; i <10 ; ++i) {
//        most.push(i);
//    }
//    most.reverse();
//    while (!most.isEmpty())
//        cout<<most.pop()<<endl;
    cout<<postfixEvaluation("135*+82/-")<<endl;
    cout<<infixEvaluation("1+3*5-8/2")<<endl;
    cout<<convertInfixToPostfix("1+3*5-8/2")<<endl;
    return 0;
}