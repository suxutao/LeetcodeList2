#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
using ll = long long;

struct Tree {
    int n;
    vector<ll> v;

    Tree(int n) : v(n + 1), n(n) {}

    void update(int x, ll val) {
        while (x <= n) {
            v[x] += val;
            x += x & -x;
        }
    }

    ll pre(int x) {
        ll ans = 0;
        while (x > 0) {
            ans += v[x];
            x -= x & -x;
        }
        return ans;
    }
};

class Solution {
public:

    long long minInversionCount(vector<int> &nums, int k) {
        int n = nums.size();
        ll ans = LLONG_MAX, sum = 0;
        vector<array<int, 2>> v(n);
        vector<ll> s(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {nums[i], i};
        }
        ranges::sort(v);
        for (int i = 0; i < n; ++i) {
            nums[n - v[i][1] - 1] = i + 1;
        }

        Tree tree(n);
        for (int i = 0; i < k; ++i) {
            tree.update(nums[i], 1);
            sum += tree.pre(nums[i] - 1);
        }
        ans = min(ans, sum);
        for (int i = k; i < n; ++i) {
            tree.update(nums[i], 1);
            sum += tree.pre(nums[i] - 1) - (tree.pre(n) - tree.pre(nums[i - k]));
            ans = min(ans, sum);
            tree.update(nums[i - k], -1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<int> v{91,95,64,42};
    Solution().minInversionCount(v, 3);
    return 0;
}