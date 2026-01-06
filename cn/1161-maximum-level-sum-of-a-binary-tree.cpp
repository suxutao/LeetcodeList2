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
    int maxLevelSum(TreeNode* root) {
        int ans=1,mx=INT_MIN,cen=1;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()){
            int sz=q.size(),cnt=0;
            for (int i = 0; i < sz; ++i) {
                TreeNode*p=q.front();
                cnt+=p->val;
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
                q.pop();
            }
            if (cnt>mx){
                mx=cnt;
                ans=cen;
            }
            cen++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}