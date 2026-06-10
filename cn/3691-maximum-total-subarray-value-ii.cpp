#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct ST {
    vector<vector<int>> mn, mx;

    ST(vector<int> &a) {
        int n = a.size(), w = bit_width((unsigned) n);
        mn.resize(w, vector<int>(n));
        mx.resize(w, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            mn[0][i] = a[i];
            mx[0][i] = a[i];
        }
        for (int i = 1; i < w; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
                mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int k = bit_width((unsigned) r - l) - 1;
        int MIN = min(mn[k][l], mn[k][r - (1 << k)]);
        int MAX = max(mx[k][l], mx[k][r - (1 << k)]);
        return MAX - MIN;
    }
};

class Solution {
public:
    using ll = long long;

    long long maxTotalValue(vector<int> &nums, int k) {
        int n = nums.size();
        ll ans = 0;
        priority_queue<array<int, 3>> q;
        ST st(nums);
        for (int i = 0; i < n; ++i) {
            q.push({st.query(i, n), i, n});
        }
        while (k-- && q.top()[0]) {
            auto [d, l, r] = q.top();
            q.pop();
            ans += d;
            q.push({st.query(l, r - 1), l, r - 1});
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}