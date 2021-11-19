#include <bits/stdc++.h>
using namespace std;

struct Node // Structure
{
    int val;
    Node* left;
    Node* right;
};

struct Node* newNode(int data){
    struct Node* node = new Node();
    node->val = data;
    node->left = node->right = NULL;
    return node;
}

int solve(Node* root, int &res){
    if(root==NULL) return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = 1 + max(l , r);
    int ans = max(temp, 1 + l + r);
    res = max(res, ans);

    return temp;
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);

    int res = INT_MIN;
    solve(root, res);

    cout << res << endl;
    return 0 ;
}