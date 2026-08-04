#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
using ll = long long;

struct Tree {
    int n;
    vector<int> tree;

    Tree(int n) : n(n), tree(n + 1) {}

    void insert(int x, int d) {
        while (x <= n) {
            tree[x] += d;
            x += x & -x;
        }
    }

    ll pre(int x) {
        ll ans = 0;
        while (x > 0) {
            ans += tree[x];
            x -= x & -x;
        }
        return ans;
    }
};

class Solution {
public:

    long long countRatioSubarrays(vector<int> &nums, int a, int b) {
        int n = nums.size();
        ll ans = 0;
        vector<ll> pre(n + 1);
        unordered_map<ll, int> m;
        Tree tree(n+1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (nums[i] & 1 ? a : -b);
        }
        vector<ll> ps(pre);
        ranges::sort(ps);
        ps.erase(ranges::unique(ps).begin(), ps.end());
        for (int i = 0; i < ps.size(); ++i) {
            m[ps[i]] = i + 1;
        }
        for (int i = 0; i <= n; ++i) {
            ans += tree.pre(m[pre[i]]);
            tree.insert(m[pre[i]], 1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}