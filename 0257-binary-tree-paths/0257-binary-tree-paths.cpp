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
    void printPaths(TreeNode* root, string temp, vector<string> &ans) {
        if(root == NULL) return;
        if(root->left || root->right) temp += to_string(root->val) + "->";
        else {
            temp += to_string(root->val);
            ans.push_back(temp);
        }
        printPaths(root->left, temp, ans);
        printPaths(root->right, temp, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        printPaths(root, temp, ans);
        return ans;
    }
};