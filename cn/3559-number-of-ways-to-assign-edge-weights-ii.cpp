#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct LCA {
    vector<int> depth;
    vector<vector<int>> pa;

    LCA(vector<vector<int>> &edges) {
        int n = edges.size() + 1, w = bit_width((unsigned) n);
        vector<vector<int>> g(n);
        for (auto &i: edges) {
            g[i[0] - 1].push_back(i[1] - 1);
            g[i[1] - 1].push_back(i[0] - 1);
        }
        depth.resize(n);
        pa.resize(n, vector<int>(w, -1));
        auto dfs = [&](this auto &&dfs, int u, int fa) -> void {
            pa[u][0] = fa;
            for (int i: g[u]) {
                if (i != fa) {
                    depth[i] = depth[u] + 1;
                    dfs(i, u);
                }
            }
        };
        dfs(0, -1);
        for (int i = 0; i < w - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (~pa[j][i])
                    pa[j][i + 1] = pa[pa[j][i]][i];
            }
        }
    }

    int get_kth(int node, int k) {
        for (; k; k &= k - 1) {
            node = pa[node][countr_zero(unsigned(k))];
        }
        return node;
    }

    int get_lca(int x, int y) {
        if (depth[x] > depth[y])
            swap(x, y);
        y = get_kth(y, depth[y] - depth[x]);
        if (y == x)
            return x;
        for (int i = pa[x].size() - 1; i >= 0; --i) {
            if (pa[x][i] != pa[y][i]) {
                x = pa[x][i];
                y = pa[y][i];
            }
        }
        return pa[x][0];
    }

    int get_dis(int x, int y) {
        return depth[x] + depth[y] - 2 * depth[get_lca(x, y)];
    }
};

class Solution {
public:
    const int N = 1e9 + 7;
    using ll = long long;

    ll fast(ll a, ll x) {
        ll ans = 1;
        while (x) {
            if (x & 1)
                ans = ans * a % N;
            a = a * a % N;
            x >>= 1;
        }
        return ans;
    }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries) {
        LCA lca(edges);
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            auto &q = queries[i];
            if (q[0] == q[1]) {
                ans[i] = 0;
            } else {
                int x = lca.get_dis(q[0] - 1, q[1] - 1);
                ans[i] = fast(2, x - 1);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}