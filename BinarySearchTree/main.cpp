#include <iostream>
#include <vector>
using namespace std;
class BST{
private:
    struct Node{
        int data;
        Node* right= nullptr;
        Node* left= nullptr;
        Node(int data):data(data){}
    };
    Node* Root= nullptr;

    void print_inorder(Node* root){
        if (root== nullptr)return;
            print_inorder(root->left);
            cout<<root->data<<" ";
            print_inorder(root->right);
    }
    bool search(Node* root,int target){
        if (root== nullptr)return false;
        if (root->data==target)return true;
        if (target<root->data)
            return search(root->left,target);
        return search(root->right,target);
    }
    int min(Node* root){
        if (root== nullptr)return -1;
        if (root->left== nullptr)return root->data;
        return min(root->left);
    }
    Node* min_Node(Node* root){
        if (root== nullptr)return nullptr;
        if (root->left== nullptr)return root;
        return min_Node(root->left);
    }
    Node* max_Node(Node* root){
        if (root== nullptr)return nullptr;
        if (root->right== nullptr)return root;
        return max_Node(root->right);
    }

    void insert(Node*& root,int target){
        if (root== nullptr){
            root=new Node(target);
        }else if (target<root->data){
            if (root->left== nullptr){
                root->left=new Node(target);
            }else
                insert(root->left,target);
        }else{
            if (root->right== nullptr){
                root->right=new Node(target);
            }else
                insert(root->right,target);
        }
    }
    int getSuccessor(Node* root,int target){
        if (root== nullptr)return -1;
        if (root->data==target){
            return min(root->right);
        }
        if (target<root->data)
            return getSuccessor(root->left,target);
        return getSuccessor(root->right,target);

    }

public:
    BST(){}
    void insert(int target){insert(Root,target);}
    void print_inorder(){print_inorder(Root);cout<<endl;}
    bool search(int target){return search(Root,target);}
    int upper_bound(int target){
        return getSuccessor(Root,target);
    }
    void arryToBST(vector<int>data){
        for (auto& x:data) {insert(x);}
    }
    void arryToBalancedBST(vector<int>data){
        ///make the Binary search tree balance and not linear
        for (auto& x:data) {
            insert(x);
            if (!data.empty()){
                insert(data.back());
                data.pop_back();
            }
        }
    }
    bool iterativeSearch(int target){
        Node* tmp=Root;
        while (true){
            if (tmp== nullptr)return false;
            if (tmp->data==target){return true;}
            if (target<tmp->data){tmp=tmp->left;}
            else{tmp=tmp->right;}
        }
    }

    void deleteNode(int target,Node* root){
        if (root== nullptr)return;

        if (target<root->data){
            deleteNode(target,root->left);
        }else if (target>root->data){
            deleteNode(target,root->right);
        }else{
            if (root->left== nullptr && root->right== nullptr) {
                delete root;
                root = nullptr;
            }else if(root->left== nullptr){
                //copy Child data and delete my child
                Node* Child=root->right;
                root->right=Child->right;
                root->left=Child->left;
                root->data=Child->data;
                delete Child;
            }else if (root->right== nullptr){
                //copy Child data and delete my child
                Node* Child=root->left;
                root->right=Child->right;
                root->left=Child->left;
                root->data=Child->data;
                delete Child;
            }else{
                Node* mn= min_Node(root->right);
                root->data=mn->data;
                deleteNode(root->data,root->right);
            }

        }

    }
};


int main() {



return 0;
}
