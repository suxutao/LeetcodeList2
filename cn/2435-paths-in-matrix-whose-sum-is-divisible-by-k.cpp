#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const int N=1e9+7;
    using ll = long long;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(k)));
        dp[1][1][grid[0][0]%k]=1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l < k; ++l) {
                    dp[i+1][j+1][(l+grid[i][j])%k]=(dp[i+1][j+1][(l+grid[i][j])%k]+dp[i][j+1][l]+dp[i+1][j][l])%N;
                }
            }
        }
        return dp[m][n][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}