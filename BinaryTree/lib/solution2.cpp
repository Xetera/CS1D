#include <queue>

struct TreeNode {
  int val;
  TreeNode* left  = nullptr;
  TreeNode* right = nullptr;
  explicit TreeNode(int x) : val(x) {}
};

class Solution {
  bool hasFirstMissing = false;

 public:
  bool isCompleteTree(const TreeNode* root) {
    if(!root) {
      return false;
    }
    std::queue<const TreeNode*> queue;
    queue.push(root);
    while(!queue.empty()) {
      const TreeNode* node = queue.front();
      queue.pop();
      if(node->right && !node->left) {
        return false;
      }
      if(!node->left && !node->right) {
        hasFirstMissing = true;
      }
      if(node->left && !node->right) {
        if(!hasFirstMissing) {
          hasFirstMissing = true;
        } else {
          return false;
        }
      }
      if(node->left && node->right && hasFirstMissing) {
        return false;
      }
      if(node->left)
        queue.push(node->left);
      if(node->right)
        queue.push(node->right);
    }
    return true;
  }
};
