#include <bits/stdc++.h>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *newNode(int data)
{
    BstNode *node = new BstNode();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BstNode *insert(BstNode *root, int data)
{
    if (root == NULL)
    { // Empty Tree
        root = newNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool Search(BstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == data)
        return true;
    else if (root->data >= data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    BstNode *root = NULL;

    int n, query;
    cin >> n >> query;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        root = insert(root, num);
    }

    for (int i = 0; i < query; i++)
    {
        int number;
        cin >> number;
        cout << "Number: " << number << " Result : " << Search(root, number) << endl;
    }

    return 0;
}
