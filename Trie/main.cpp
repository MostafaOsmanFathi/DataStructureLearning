#include <iostream>
#include <cstring>
using namespace std;

struct trie{
    trie* Child[26]{};
    bool isLeaf;
    trie(){
        memset(Child, NULL,sizeof Child);
        isLeaf=false;
    }
    void insert(char *str){
        if (*str=='\0') {
            isLeaf= true;
            return;
        }
        if (Child[*str-'a']==NULL){
            Child[*str-'a']=new trie;
        }
        Child[*str-'a']->insert(str+1);
    }
    bool wordExist(char *str){
        if (*str=='\0')return isLeaf;
        if (Child[*str-'a']==NULL)return false;
        return Child[*str-'a']->wordExist(str+1);
    }
    bool wordPrefixExist(char *str){
        if (*str=='\0')return true;
        if (Child[*str-'a']==NULL)return false;
        return Child[*str-'a']->wordExist(str+1);
    }

    void printAllWords(string& str){
        if (isLeaf)
            cout<<str<<endl;
        for (int i = 0; i < 26; ++i) {
            if (Child[i]!=NULL){
                str.push_back(char (i+'a'));
                Child[i]->printAllWords(str);
                str.pop_back();
            }
        }

    }
    void clear(){
        for (auto& x:Child) {
            delete x;
        }
    }
    ~trie(){
        for (auto& x:Child) {
            delete x;
        }
    }
};


int main() {
    trie tr;
    tr.insert("most");
    tr.insert("mostafa");
    string tmp;
    tr.printAllWords(tmp);
//    tr.clear();
    return 0;
}

