#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maximumProfit(vector<int>& prices, int k) {
        ll n=prices.size();
        vector<array<ll,3>>dp(k+1);
        for (int i = 1; i <= k; ++i) {
            dp[i][1]=-prices[0];
            dp[i][2]=prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j; --j) {
                dp[j][0]=max(dp[j][0],max(dp[j][1]+prices[i],dp[j][2]-prices[i]));
                dp[j][1]=max(dp[j][1],dp[j-1][0]-prices[i]);
                dp[j][2]=max(dp[j][2],dp[j-1][0]+prices[i]);
            }
        }
        return dp[k][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}