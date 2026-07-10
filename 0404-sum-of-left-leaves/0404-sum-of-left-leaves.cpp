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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
             if(temp->left){
              if(temp->left->left == nullptr &&
                   temp->left->right == nullptr){
                    sum += temp->left->val;
                }
                else{
                    q.push(temp->left);
                }
             }

            if(temp->right){
                q.push(temp->right);
            }
        }
        return sum;
    }
};