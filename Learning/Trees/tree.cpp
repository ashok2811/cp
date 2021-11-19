#include <bits/stdc++.h>
using namespace std;

struct BstNode{
    int data ;
    BstNode* left;
    BstNode* right;
};

BstNode* newNode(int data){
    BstNode* node = new BstNode();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BstNode* insert(BstNode* root, int data){
    if(root==NULL){// Empty Tree
        root = newNode(data);
        return root;
    }
    else if(data<=root->data){
        root ->left = insert(root->left, data);
    }
    else{
        root ->right = insert(root->right, data);
    }
    return root;
}


int main(){

BstNode* root  = NULL;

root = insert(root, 200);
root = insert(root, 10);

    return 0;
}

