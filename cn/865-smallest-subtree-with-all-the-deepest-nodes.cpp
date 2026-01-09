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
    unordered_map<TreeNode *, int> m;
    TreeNode *ans = nullptr,*r;

    void dfs(TreeNode *p, int depth) {
        if (!p) return;
        if (!p->left&&!p->right){
            if (depth==m[r]&&ans==nullptr){
                ans=p;
            }
            return;
        }
        if (p->left&&p->right){
            if (m[p->left]==m[p->right]&&m[p->left]+depth==m[r]&&m[ans]<m[p]){
                ans=p;
                return;
            }
        }
        dfs(p->left,depth+1);
        dfs(p->right,depth+1);
    }

    int cal(TreeNode *p) {
        if (!p) return 0;
        int res = max(cal(p->right), cal(p->left));
        return m[p] = res + 1;
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        r=root;
        m[nullptr]=0;
        cal(root);
        dfs(root, 1);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}