#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> levelNodes(levelSize);
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            int index = leftToRight ? i : levelSize - 1 - i;
            levelNodes[index] = node->val;
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        result.push_back(levelNodes);
        leftToRight = !leftToRight;
    }
    return result;
}
