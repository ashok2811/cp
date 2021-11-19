/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int solve(Node* root, int &res){
    if(root==NULL) return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    res = max(res, 1 + l + r);

    return 1 + max(l , r);;
}
    
    int diameter(Node* root) {
        // Your code here
        int res = INT_MIN;
        if (root == NULL) return 0;
        solve(root, res);
        return res;
    }
};
