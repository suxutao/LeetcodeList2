#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N = 1e9 + 7;

    int maxProductPath(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1) {
            ll ans = 1;
            for (int i = 0; i < n; ++i) {
                ans *= grid[0][i];
            }
            return ans < 0 ? -1 : ans % N;
        } else if (n == 1) {
            ll ans = 1;
            for (int i = 0; i < m; ++i) {
                ans *= grid[i][0];
            }
            return ans < 0 ? -1 : ans % N;
        }
        vector<vector<array<ll, 2>>> dp(m, vector<array<ll, 2>>(n, {-1, 0}));
        if (grid[0][0] >= 0) {
            dp[0][0][0] = grid[0][0];
        } else {
            dp[0][0][1] = grid[0][0];
        }
        for (int i = 1; i < m; ++i) {
            if (grid[i][0] > 0) {
                dp[i][0][0] = dp[i - 1][0][0] * grid[i][0];
                dp[i][0][1] = dp[i - 1][0][1] * grid[i][0];
            } else if (grid[i][0] < 0) {
                dp[i][0][0] = dp[i - 1][0][1] * grid[i][0];
                dp[i][0][1] = dp[i - 1][0][0] * grid[i][0];
            } else {
                dp[i][0][0] = 0;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (grid[0][i] > 0) {
                dp[0][i][0] = dp[0][i - 1][0] * grid[0][i];
                dp[0][i][1] = dp[0][i - 1][1] * grid[0][i];
            } else if (grid[0][i] < 0) {
                dp[0][i][0] = dp[0][i - 1][1] * grid[0][i];
                dp[0][i][1] = dp[0][i - 1][0] * grid[0][i];
            } else {
                dp[0][i][0] = 0;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] > 0) {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) * grid[i][j];
                    dp[i][j][1] = min(dp[i - 1][j][1], dp[i][j - 1][1]) * grid[i][j];
                } else if (grid[i][j] < 0) {
                    dp[i][j][0] = min(dp[i - 1][j][1], dp[i][j - 1][1]) * grid[i][j];
                    dp[i][j][1] = max(dp[i - 1][j][0], dp[i][j - 1][0]) * grid[i][j];
                } else {
                    dp[i][j][0] = 0;
                }
            }
        }
        return dp[m - 1][n - 1][0] < 0 ? -1 : dp[m - 1][n - 1][0] % N;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}