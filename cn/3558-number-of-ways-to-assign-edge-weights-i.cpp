#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const int N = 1e9 + 7;

    int assignEdgeWeights(vector<vector<int>> &edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);
        for (auto &i: edges) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        auto dfs = [&](this auto &&dfs, int u, int fa) -> int {
            int res = 0;
            for (auto &i: g[u]) {
                if (i == fa)
                    continue;
                res = max(res, dfs(i, u));
            }
            return res + 1;
        };
        long long depth = dfs(1, 1), ans = 1;
        for (int i = 0; i < depth - 2; ++i) {
            ans = ans * 2 % N;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}