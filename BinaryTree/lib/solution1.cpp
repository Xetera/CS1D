struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void invertTree(TreeNode* node) {
    if(!node)
      return;
    TreeNode* temp = node->left;
    node->left     = node->right;
    node->right    = temp;
    if(node->left) {
      invertTree(node->left);
    }
    if(node->right) {
      invertTree(node->right);
    }
  }
};