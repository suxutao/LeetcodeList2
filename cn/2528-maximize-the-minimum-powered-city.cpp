#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long maxPower(vector<int> &stations, int r, int k) {
        int n = stations.size();
        ll mn = LLONG_MAX, mx = 0;
        vector<ll> v(n + 1), pre(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = stations[i - 1] + pre[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            v[i] = pre[min(n, i + r + 1)] - pre[max(0, i - r)];
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);
        }
        auto check = [&](ll x) -> bool {
            ll cost = 0, sum = 0, cha;
            vector<ll> t(n+1,0);
            for (int i = 0; i < n; ++i) {
                sum += t[i];
                if (sum < x - v[i]) {
                    cha = x - sum - v[i];
                    cost += cha;
                    if (cost > k)
                        return false;
                    sum+=cha;
                    t[min(n, i + r*2 + 1)] -= cha;
                }
            }
            return true;
        };
        ll L = mn, R = mx + k + 1, mid;
        while (L+1 < R) {
            mid = (L + R) >> 1;
            if (check(mid)) {
                L = mid;
            } else {
                R = mid;
            }
        }
        return L;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}