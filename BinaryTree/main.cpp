#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

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
    void generationTree(deque<int>&preorder,deque<int>&inorder,Node*& root,int start=0,int end=-1){
        if (end==-1)end=inorder.size()-1;
        if (preorder.empty())return;
        for (int i = start; i <=end; ++i) {
            if (inorder.at(i)==root->data){
                if (start<i){
                    root->left=new Node(preorder.front());
                    preorder.pop_front();
                    generationTree(preorder,inorder,root->left,start,i-1);
                }
                if (i<end){
                    root->right=new Node(preorder.front());
                    preorder.pop_front();
                    generationTree(preorder,inorder,root->right,i+1,end);
                }
                break;
            }
        }

    }

public:
    void generationTreeQueue(Node* root,queue<pair<int,bool>>&qu){
        if (qu.empty())return;

            root->left=new Node(qu.front().first);
            if (!qu.front().second) {
                qu.pop();
                generationTreeQueue(root->left, qu);
            }else
                qu.pop();


            if (!qu.empty()){
                root->right=new Node(qu.front().first);
                if (!qu.front().second) {
                    qu.pop();
                    generationTreeQueue(root->right, qu);
                }else
                    qu.pop();
            }

    }
    BinaryTree(){}

    BinaryTree(deque<int>preorder,deque<int>inorder){
        Root=new Node(preorder.front());
        preorder.pop_front();
        generationTree(preorder,inorder,Root);
    }
    ///                   value  isLeaf
    BinaryTree(queue<pair<int  , bool>>qu){

        Root=new Node(qu.front().first);
        qu.pop();
        generationTreeQueue(Root,qu);
    }
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
        cout<<endl;
    }
    void levelOrderSpiral(){
        queue<Node *> qu;
        stack<int> st;
        qu.push(Root);
        cout<<Root->data<<" ";
        bool isRev{false};
        while (!qu.empty()) {
            int sz=qu.size();
            while (sz--){
                if (isRev&&Root!=qu.front())
                    cout << qu.front()->data << " "<<flush;
                Node *Cur = qu.front();
                qu.pop();
                if (Cur->left != nullptr) {
                    qu.push(Cur->left);
                    if (isRev){
                        st.push(Cur->left->data);
                    }
                }
                if (Cur->right != nullptr) {
                    qu.push(Cur->right);
                    if (isRev){
                        st.push(Cur->right->data);
                    }
                }
            }
            while (!st.empty())
                cout<<st.top()<<" ",st.pop();

            isRev=!isRev;
        }
        cout<<endl;
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
    ///tree generation using preorder and isLeaf bool
    queue<pair<int,bool>>qu;
    qu.push({1,0});
    qu.push({2,1});
    qu.push({3,1});
    BinaryTree testGenerationQu(qu);
    testGenerationQu.printPreOrder();

    cout << "==================\n";
    ///tree generation using preorder and inorder
    BinaryTree testGeneration({1,2,4,7,8,5,9,3,6,10},{7,4,8,2,5,9,1,3,10,6});
    testGeneration.printPreOrder();
    testGeneration.levelOrderTraversal();
    cout << "==================\n";
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
    cout << "==================\n";

    BinaryTree TestTree;
    TestTree.add({1,2,4,8},{'L','L','L','L'});
    TestTree.add({2,5,11},{'L','R','R'});
    TestTree.add({2,5,10},{'L','R','L'});
    TestTree.add({2,4,9},{'L','L','R'});
    TestTree.add({3,7,15},{'R','R','R'});
    TestTree.add({3,7,14},{'R','R','L'});
    TestTree.add({3,6,12},{'R','L','L'});
    TestTree.add({3,6,15},{'R','L','R'});
    TestTree.levelOrderTraversal();
    TestTree.levelOrderSpiral();

    return 0;
}

