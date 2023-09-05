#include <iostream>
#include "Vector.h"
using namespace std;
int main() {
Vector mostafa;
mostafa.push_back(1);
mostafa.push_back(2);
    mostafa.insert(3,3);
    mostafa.insert(4,4);
for (int i = 0; i < mostafa.Size(); ++i) {
        cout<<mostafa.at(i)<<" ";
    }
    cout<<endl;
    mostafa.right_rotation(2);
    cout<<mostafa.pop(0)<<endl;
    for (int i = 0; i < mostafa.Size(); ++i) {
        cout<<mostafa.at(i)<<" ";
    }
    return 0;
}
