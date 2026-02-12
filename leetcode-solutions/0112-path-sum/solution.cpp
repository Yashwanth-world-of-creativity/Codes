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
    // bool Traverse(TreeNode* root,int k,int curr){
       
    //         if(root->left==NULL&& root->right==NULL&&curr==k)
    //         return true;
    //         bool l=false,r=false;
    //         if(root->left!=nullptr)
    //         l=Traverse(root->left,k,curr+root->left->val);

    //         if(root->right!=nullptr)
    //         r=Traverse(root->right,k,curr+root->right->val);
    //         return l||r;
    // }
    bool Traverse(TreeNode* root,int k,int curr){
       
            if(root->left==NULL&& root->right==NULL&&curr==k)
            return true;
           
            if(root->left!=nullptr&&Traverse(root->left,k,curr+root->left->val)==true)
            return true;

            if(root->right!=nullptr&& Traverse(root->right,k,curr+root->right->val))
             return true;

            return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
         if(root==nullptr) return false;
        return Traverse(root,targetSum,root->val);
    }
};
