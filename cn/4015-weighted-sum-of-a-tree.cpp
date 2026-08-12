#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long weightedSum(vector<int> &parent, vector<int> &nums) {
        int n = parent.size();
        ll ans = 0;
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            g[parent[i]].push_back(i);
        }
        auto dfs = [&](this auto &&dfs, int u) -> int {
            int res = 1;
            for (auto &i: g[u]) {
                res = max(res, dfs(i) + 1);
            }
            return res;
        };
        int depth = dfs(0);
        auto dfs2 = [&](this auto &&dfs2, int u, int h) -> void {
            ans += (ll) nums[u] * (depth - h + 1);
            for (auto &i: g[u]) {
                dfs2(i, h + 1);
            }
        };
        dfs2(0, 1);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}