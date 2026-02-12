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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
               vector<int>level;
            for(int i=0,n=q.size();i<n;++i){
                TreeNode* temp=q.front();
             
                q.pop();
                level.push_back(temp->val);
                 if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
               
            }
            if(ans.size()%2==1){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};
