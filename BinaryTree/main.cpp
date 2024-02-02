#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>

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

    int TreeMax(Node *root) {
        if (root == nullptr)return INT_MIN;
        return max(root->data, max(TreeMax(root->left), TreeMax(root->right)));
    }

    int TreeMin(Node *root) {
        if (root == nullptr)return INT_MAX;
        return min(root->data, max(TreeMin(root->left), TreeMin(root->right)));
    }

    int TreeHeight(Node *root) {
        if (root == nullptr)return 0;

        int rightPath = 1 + TreeHeight(root->right);
        int leftPath = 1 + TreeHeight(root->left);
        return max(rightPath, leftPath);
    }

    int CountAllNodes(Node *Root) {
        if (Root == nullptr)return 0;
        return 1 + CountAllNodes(Root->left) + CountAllNodes(Root->right);
    }

    int CountLeafNode(Node *root) {
        if (root == nullptr)return 0;
        else if (root->left == nullptr && root->right == nullptr)return 1;
        int tmp = CountLeafNode(root->left) + CountLeafNode(root->right);
        return tmp;
    }

    bool IsExist(Node *root, int val) {
        if (root == nullptr)return false;
        else if (root->data == val)return true;
        return IsExist(root->left, val) || IsExist(root->right, val);
    }

    void ClearTree(Node *root) {
        if (root == nullptr)return;
        ClearTree(root->left);
        ClearTree(root->right);
        delete root;
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

    bool isPerfectTree() {
        return countAllNodes() == (2 << treeHeight()) - 1;
    }

    inline int treeHeight() {
        return TreeHeight(Root) - 1;
    }

    inline int treeMax() {
        return TreeMax(Root);
    }

    inline int treeMin() {
        return TreeMin(Root);
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

    inline int countAllNodes() {
        return CountAllNodes(Root);
    }

    inline int countLeafNode() {
        return CountLeafNode(Root);
    }

    void levelOrderTraversal() {///BFS
        queue<Node *> qu;
        qu.push(Root);
        while (!qu.empty()) {
            cout << qu.front()->data << " ";
            Node *Cur = qu.front();
            qu.pop();
            if (Cur->left != nullptr)qu.push(Cur->left);
            if (Cur->right != nullptr)qu.push(Cur->right);
        }
    }

    inline bool isExist(int val) {
        return IsExist(Root, val);
    }

    inline void clearTree() {
        ClearTree(Root);
        Root = nullptr;
    }

    bool isEmpty() {
        return Root == nullptr;
    }

    ~BinaryTree() {
        ClearTree(Root);
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
    cout << tree.treeMax() << endl;
    cout << tree.treeMin() << endl;
    cout << tree.treeHeight() << endl;
    cout << tree.countAllNodes() << endl;
    cout << tree.countLeafNode() << endl;
    cout << boolalpha << tree.isExist(7) << endl;
    cout << boolalpha << tree.isExist(120) << endl;
    cout << boolalpha << tree.isPerfectTree() << endl;

    cout << "==================\n";
    BinaryTree most;
    most.add({1}, {'R'});
    most.add({3}, {'L'});
    most.add({13, 8}, {'R', 'R'});
    most.add({13, 7}, {'R', 'L'});
    most.printPreOrder();
    cout << most.treeMax() << endl;
    cout << most.treeMin() << endl;
    cout << most.treeHeight() << endl;
    cout << most.countAllNodes() << endl;
    cout << most.countLeafNode() << endl;
    cout << boolalpha << most.isExist(13) << endl;
    cout << boolalpha << most.isExist(120) << endl;
    cout << boolalpha << most.isPerfectTree() << endl;


    cout << "==================\n";
    BinaryTree PerfectTree;
    PerfectTree.add({2}, {'L'});
    PerfectTree.add({3, 5}, {'L', 'L'});
    PerfectTree.add({3, 6}, {'L', 'R'});
    PerfectTree.add({13, 8}, {'R', 'R'});
    PerfectTree.add({13, 7}, {'R', 'L'});
    PerfectTree.printPreOrder();
    cout << boolalpha << PerfectTree.isPerfectTree() << endl;


    cout << "==================\n";
    BinaryTree Tree;
    Tree.add({2}, {'L'});
    Tree.add({3, 5}, {'L', 'L'});
    Tree.add({3, 6}, {'L', 'R'});
    Tree.add({13, 8}, {'R', 'R'});
    Tree.add({13, 7}, {'R', 'L'});
    Tree.printPastOrder();
//    Tree.clearTree();
    Tree.levelOrderTraversal();///DFS
    return 0;
}

