#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    int climbStairs(int n, vector<int>& costs) {
        vector<ll>dp(n+1);
        for (int i = 1; i <= n; ++i) {
            dp[i]=costs[i-1]+1+dp[i-1];
            if (i>1) dp[i]=min(dp[i],costs[i-1]+4+dp[i-2]);
            if (i>2) dp[i]=min(dp[i],costs[i-1]+9+dp[i-3]);
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}