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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q)
            return NULL;
        while(max(p->val, q->val) < root->val || min(p->val, q->val) > root->){
            if(max(p->val, q->val) < root->val)
                root = root->left;
            if(min(p->val, q->val) > root->val)
                root = root->right;
        }
        return root;
    }
};