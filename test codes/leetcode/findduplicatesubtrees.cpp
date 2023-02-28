#include <bits/stdc++.h>

using namespace std;
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> count;
        postorder(root, count, result);
        return result;
    }
    
private:
    string postorder(TreeNode* node, unordered_map<string, int>& count, vector<TreeNode*>& result) {
        if (!node) {
            return "#";
        }
        string left = postorder(node->left, count, result);
        string right = postorder(node->right, count, result);
        string subtree = left + "," + right + "," + to_string(node->val);
        if (count[subtree] == 1) {
            result.push_back(node);
        }
        count[subtree]++;
        return subtree;
    }
};