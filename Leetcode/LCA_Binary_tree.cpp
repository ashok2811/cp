/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> level;

    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = root;
        level[root] = 0;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left !=NULL){
                q.push(curr->left);
               
                
                level[curr->left] = level[curr] +1;
              
                parent[(curr->left)] = curr;
             
            }
            if(curr->right !=NULL){
             
                q.push(curr->right);
       
                level[curr->right] = level[curr] +1;

                parent[(curr->right)] = curr;
                
            }
        }
    }
    
    TreeNode* LCA(TreeNode* node1, TreeNode* node2){
    if(level[node1] > level[node2]) 
        swap(node1,node2);
    
    int d = level[node2] - level[node1];

    while(d > 0){
        node2 = parent[node2];
     
        d--;
    }
    if(node1 == node2){ return node1; }

    while(parent[node1] != parent[node2]){
        node1 = parent[node1];
        node2 = parent[node2];
    }
        
    return parent[node1];
}
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bfs(root);
        return LCA(p, q);
    }
};