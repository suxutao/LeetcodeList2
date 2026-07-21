#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
    int countDominantNodes(TreeNode* root) {
        int ans=0;
        auto dfs=[&](this auto&&dfs,TreeNode*p)->int{
            if (!p->left&&!p->right){
                ans++;
                return p->val;
            }
            int mx=p->val;
            if (p->left){
                mx=max(mx,dfs(p->left));
            }
            if (p->right){
                mx=max(mx,dfs(p->right));
            }
            if (mx==p->val)
                ans++;
            return mx;
        };
        dfs(root);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}