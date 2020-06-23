/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void help(TreeNode* root,int &c){
        if(!root){
            return;
        }
        c++;
        help(root->left,c);
        help(root->right,c);
        
    }
    int countNodes(TreeNode* root) {
        int c=0;
        help(root,c);
        return c;
    }
};
