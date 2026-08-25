#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long elevatorRequests(int n, int start, vector<vector<int> > &requests) {
        int m = requests.size();
        vector<vector<ll>> dp(1 << m, vector<ll>(m));
        for (int i = 0; i < m; ++i) {
            dp[1 << i][i] = max(abs(requests[i][1] - start), requests[i][0]);
        }
        for (int mask = 1; mask < 1 << m; ++mask) {
            if ((mask & (mask - 1)) == 0)
                continue;
            for (int i = 0; i < m; ++i) {
                if ((mask & (1 << i)) == 0)
                    continue;
                dp[mask][i] = LLONG_MAX;
                for (int j = 0; j < m; ++j) {
                    if (((mask ^ (1 << i)) & (1 << j)) == 0)
                        continue;
                    dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + abs(requests[i][1] - requests[j][1]));
                }
                dp[mask][i] = max(dp[mask][i], (ll)requests[i][0]);
            }
        }
        return ranges::min(dp.back());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
