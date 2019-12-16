
#include <vector>

using std::vector;
using Orders = vector<int>;

struct TreeNode {
  int val;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
  explicit TreeNode(int x) : val(x) {}
};

class Solution {
 public:
  TreeNode* constructFromPrePost(Orders& pre, Orders& post) {
    auto* root = new TreeNode(2);
  }
  recurse() {

  }

};
