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
private:
    void findPaths(TreeNode* root, int targetSum, vector<int> temp, vector<vector<int>> &ans) {
        if(root == NULL) return;
        int newSum = targetSum - root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && newSum == 0) {
            ans.push_back(temp);
        }
        findPaths(root->left, newSum, temp, ans);
        findPaths(root->right, newSum, temp, ans);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> temp;
        findPaths(root, targetSum, temp, ans);
        return ans;
    }
};