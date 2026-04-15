#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<bool>>>dp(m+1,vector<vector<bool>>(n+1,vector<bool>(1024)));
        dp[0][1][0]=dp[1][0][0]=1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 0; k < 1024; ++k) {
                    int idx = k ^ grid[i-1][j-1];
                    dp[i][j][idx] = dp[i][j][idx] || dp[i-1][j][k];
                    dp[i][j][idx] = dp[i][j][idx] || dp[i][j-1][k];
                }
            }
        }
        for (int i = 0; i < 1024; ++i) {
            if (dp[m][n][i])
                return i;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}