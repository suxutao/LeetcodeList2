#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(),n=coins[0].size();
        vector<vector<array<int,3>>>dp(m+1,vector<array<int,3>>(n+1,{INT_MIN/2,INT_MIN/2,INT_MIN/2}));
        dp[0][1][0]=dp[1][0][0]=0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i+1][j+1][0]=coins[i][j]+max(dp[i][j+1][0],dp[i+1][j][0]);
                dp[i+1][j+1][1]=coins[i][j]+max(dp[i][j+1][1],dp[i+1][j][1]);
                dp[i+1][j+1][2]=coins[i][j]+max(dp[i][j+1][2],dp[i+1][j][2]);
                if (coins[i][j]<0){
                    dp[i+1][j+1][1]=max(dp[i+1][j+1][1],max(dp[i][j+1][0],dp[i+1][j][0]));
                    dp[i+1][j+1][2]=max(dp[i+1][j+1][2],max(dp[i][j+1][1],dp[i+1][j][1]));
                }
            }
        }
        return ranges::max(dp[m][n]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}