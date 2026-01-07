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
    const int N=1e9+7;
    using ll = long long;
    ll sum=0,ans=0;
    void dfs_sum(TreeNode*p){
        if (!p) return;
        dfs_sum(p->left);
        sum+=p->val;
        dfs_sum(p->right);
    }
    ll dfs(TreeNode*p){
        ll l=0,r=0;
        if (p->left){
            l=dfs(p->left);
            ans=max(ans,l*(sum-l));
        }
        if (p->right){
            r=dfs(p->right);
            ans=max(ans,r*(sum-r));
        }
        return l+r+p->val;
    }
    int maxProduct(TreeNode* root) {
        dfs_sum(root);
        dfs(root);
        return ans%N;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}