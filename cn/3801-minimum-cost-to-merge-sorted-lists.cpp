#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    vector<int> merge(vector<int> &a, vector<int> &b) {
        int na = a.size(), nb = b.size(), pa = 0, pb = 0, p = 0;
        vector<int> res(na + nb);
        while (pa < na && pb < nb) {
            if (a[pa] <= b[pb]) {
                res[p++] = a[pa++];
            } else {
                res[p++] = b[pb++];
            }
        }
        while (pa < na) {
            res[p++] = a[pa++];
        }
        while (pb < nb) {
            res[p++] = b[pb++];
        }
        return res;
    }

    long long minMergeCost(vector <vector<int>> &lists) {
        int n = lists.size(), u = 1 << n;
        vector <vector<int>> sorted(u);
        vector <ll> dp(u);
        for (int i = 0; i < n; ++i) {
            int b = 1 << i;
            for (int j = 0; j < b; ++j) {
                sorted[b | j] = merge(lists[i], sorted[j]);
            }
        }
        for (int i = 3; i < u; ++i) {
            if ((i & (i - 1)) == 0)
                continue;
            dp[i] = LLONG_MAX;
            for (int j = i & (i - 1); j > (i ^ j); j = (j - 1) & i) {
                int k = i ^ j;
                int medj = sorted[j][(sorted[j].size() - 1) / 2];
                int medk = sorted[k][(sorted[k].size() - 1) / 2];
                dp[i] = min(dp[i], dp[j] + dp[k] + abs(medj - medk));
            }
            dp[i] += sorted[i].size();
        }
        return dp[u - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}