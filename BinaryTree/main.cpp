#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class BinaryTree {
private:
    struct Node {
        Node *right = nullptr;
        Node *left = nullptr;
        int data;

        Node(int data) : data(data) {}
    };

    Node *Root = nullptr;

    void PrintPreOrder(Node *root) {
        if (root == nullptr)return;
        cout << root->data << " ";
        PrintPreOrder(root->left);
        PrintPreOrder(root->right);
    }

    void PrintInOrder(Node *root) {
        if (root == nullptr)return;
        PrintInOrder(root->left);
        cout << root->data << " ";
        PrintInOrder(root->right);
    }

    void PrintPastOrder(Node *root) {
        if (root == nullptr)return;
        PrintPastOrder(root->left);
        PrintPastOrder(root->right);
        cout << root->data << " ";
    }

public:

    void add(vector<int> values, vector<char> direction) {
        assert(values.size() == direction.size());
        Node *Cur = Root;
        for (int i = 0; i < values.size(); ++i) {
            assert(direction.at(i) == 'L' || direction.at(i) == 'R');
            if (Root == nullptr) {
                Root = new Node(values.at(i));
                Cur = Root;
            } else if (direction.at(i) == 'L') {
                if (Cur->left == nullptr) {
                    Cur->left = new Node(values.at(i));
                } else
                    assert(Cur->left->data == values.at(i));
                Cur = Cur->left;
            } else {

                if (Cur->right == nullptr) {
                    Cur->right = new Node(values.at(i));
                } else
                    assert(Cur->right->data == values.at(i));
                Cur = Cur->right;
            }
        }
    }

    inline void printPastOrder() {
        PrintPastOrder(Root);
        cout << endl;
    }

    inline void printInOrder() {
        PrintInOrder(Root);
        cout << endl;
    }

    inline void printPreOrder() {
        PrintPreOrder(Root);
        cout << endl;
    }

};

int main() {
    BinaryTree tree;
    tree.add({1}, {'L'});
    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'});
    tree.add({3, 6, 10}, {'R', 'R', 'L'});

    tree.printPreOrder();
    tree.printInOrder();
    tree.printPastOrder();

    return 0;
}

