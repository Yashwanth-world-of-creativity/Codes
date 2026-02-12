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
//k=target
void dfs(TreeNode* root,int k,int curr,vector<int>&temp ,vector<vector<int>> &ans){
        if(root->left==nullptr&&root->right==nullptr&&curr==k)
        {
            ans.push_back(temp);
            return;
        }
        if(root->left!=NULL){
            temp.push_back(root->left->val);
            dfs(root->left,k,curr+root->left->val,temp,ans);
            temp.pop_back();//backtracking
        }

        if(root->right!=NULL){
            temp.push_back(root->right->val);
            dfs(root->right,k,curr+root->right->val,temp,ans);
            temp.pop_back();//backtracking
        }

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        return {};
        vector<int>temp;
        vector<vector<int>>ans;
                temp.push_back(root->val);
        dfs(root,targetSum,root->val,temp,ans);
        return ans;
    }
};
// class Solution {
// public:
    
//     void dfs(TreeNode* root, int target, int curr,
//              vector<int>& path, vector<vector<int>>& ans) {
        
//         if(root == NULL) return;

//         path.push_back(root->val);
//         curr += root->val;

//         // If leaf node
//         if(root->left == NULL && root->right == NULL) {
//             if(curr == target) {
//                 ans.push_back(path);
//             }
//         }

//         dfs(root->left, target, curr, path, ans);
//         dfs(root->right, target, curr, path, ans);

//         path.pop_back(); // backtracking
//     }

//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>> ans;
//         vector<int> path;
//         dfs(root, targetSum, 0, path, ans);
//         return ans;
//     }
// };
