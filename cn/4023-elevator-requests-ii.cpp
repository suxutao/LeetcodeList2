#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long elevatorRequests(int n, int start, vector<int> &requests) {
        requests.insert(requests.end(), {start, -1, n});
        ranges::sort(requests);
        int m = requests.size(), index = ranges::lower_bound(requests, start) - requests.begin();
        vector<vector<array<ll, 2> > > dp(index + 1, vector<array<ll, 2> >(m, {LLONG_MAX/2,LLONG_MAX/2}));
        for (int i = 1; i <= index; ++i) {
            for (int j = m - 2; j >= index; --j) {
                if (i == 1 && j == m - 2) {
                    dp[i][j][0] = dp[i][j][1] = 0;
                    continue;
                }
                ll cnt = m - j + i - 3;
                dp[i][j][0] = min(dp[i - 1][j][0] + (requests[i] - requests[i - 1]) * cnt,
                                  dp[i][j + 1][1] + (requests[j + 1] - requests[i]) * cnt);
                dp[i][j][1] = min(dp[i][j + 1][1] + (requests[j + 1] - requests[j]) * cnt,
                                  dp[i - 1][j][0] + (requests[j] - requests[i - 1]) * cnt);
            }
        }
        return dp[index][index][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
