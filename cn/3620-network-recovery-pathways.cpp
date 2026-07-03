#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k) {
        int n = online.size(), mx = 0;
        vector<vector<array<int, 2>>> g(n);
        for (auto &i: edges) {
            if (online[i[0]] && online[i[1]] && i[2] <= k) {
                g[i[0]].push_back({i[1], i[2]});
                mx = max(mx, i[2]);
            }
        }
        auto check = [&](int x) -> bool {
            vector<long long> memo(n, -1);
            auto dfs = [&](this auto &&dfs, int u) -> long long {
                if (u == n - 1)
                    return 0;
                auto &ans = memo[u];
                if (ans != -1) {
                    return memo[u];
                }
                ans = LLONG_MAX / 2;
                for (auto &[to, w]: g[u]) {
                    if (w < x)
                        continue;
                    ans = min(ans, dfs(to) + w);
                }
                return ans;
            };
            return dfs(0) <= k;
        };
        int l = 0, r = mx + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}