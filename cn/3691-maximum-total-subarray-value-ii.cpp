#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct ST {
    vector<vector<int>> Min, Max;

    ST(const vector<int> &a) {
        int n = a.size(), w = bit_width((unsigned) n);
        Max.assign(w, vector<int>(n));
        Min.assign(w, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            Max[0][i] = a[i];
            Min[0][i] = a[i];
        }
        for (int i = 1; i < w; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                Max[i][j] = max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
                Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int w = bit_width((unsigned) r - l) - 1;
        int MAX = max(Max[w][l], Max[w][r - (1 << w)]);
        int MIN = min(Min[w][l], Min[w][r - (1 << w)]);
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