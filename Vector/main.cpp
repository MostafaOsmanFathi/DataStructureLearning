#include <iostream>
#include "Vector.h"
using namespace std;
int main() {
Vector mostafa;
mostafa.push_back(10);
mostafa.push_back(11);
mostafa.push_back(13);

    mostafa.insert(1,15);
    for (int i = 0; i < mostafa.Size(); ++i) {
        cout<<mostafa.at(i)<<" ";
    }
    return 0;
}
