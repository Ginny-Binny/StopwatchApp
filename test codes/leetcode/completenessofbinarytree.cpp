#include<std/c++.h>
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool reachedEnd = false;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (reachedEnd && (curr->left || curr->right)) {
                return false;
            }

            if (!curr->left && curr->right) {
                return false;
            }

            if ((curr->left && !curr->right) || (!curr->left && !curr->right)) {
                reachedEnd = true;
            }

            if (curr->left) {
                q.push(curr->left);
            }

            if (curr->right) {
                q.push(curr->right);
            }
        }

        return true;
    }
};
