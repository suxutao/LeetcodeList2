#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDeletionSize(vector<string> &strs) {
        int m = strs.size(), n = strs[0].size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                bool da = true;
                for (int k = 0; k < m; ++k) {
                    if (strs[k][i] < strs[k][j]) {
                        da = false;
                        break;
                    }
                }
                if (da)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return n - ranges::max(dp);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}