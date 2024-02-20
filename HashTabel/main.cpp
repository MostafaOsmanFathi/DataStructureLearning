#include <iostream>
#include <vector>
#include <list>
using namespace std;
class HashString{
private:
    vector<list<string>>HashTable;

    int hash_string(const string& str){
        long long sum{0},n=str.size();
        for (int i = 0; i <str.size() ; ++i) {
            sum=(sum*26+str.at(i)-'a')%n;
        }
        return sum%n;
    }
public:
    void insert(string s){
        int idx=hash_string(s);
        if (idx>=HashTable.size()){HashTable.resize(idx+1);}
        for (const auto& x:HashTable[idx]) {
            if (x==s){return;}
        }
        HashTable[idx].push_back(s);
    }
    bool remove(string s){
        int idx= hash_string(s);
        if (idx>=HashTable.size())return false;

        for (auto it=HashTable[idx].begin();it!=HashTable[idx].end();++it){
            if (*it==s){
                HashTable[idx].erase(it);
                return true;
            }
        }
        return false;
    }
    bool find(string s){
        int idx= hash_string(s);
        if (idx>=HashTable.size())return false;

        for (const auto &x:HashTable[idx]) {
            if (x==s){
                return true;
            }
        }
        return false;
    }


};
int main() {
    cout<<boolalpha;
    HashString mos;
    mos.insert("mostafa3");
    mos.insert("mostafa1");
    mos.insert("mostafa2");
    cout<<mos.find("mostafa1")<<endl;
    cout<<mos.find("mostafa")<<endl;

    mos.remove("mostafa1");
    cout<<mos.find("mostafa1")<<endl;

    return 0;
}
