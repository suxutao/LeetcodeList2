#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    ll f(ll x, ll k) {
        ll ans = 1;
        for (int i = 0; i < k; ++i) {
            ans *= x;
        }
        return ans;
    }

    int countKthRoots(int l, int r, int k) {
        if (k == 1)
            return r - l + 1;
        int ans = 0;
        for (int i = 0; f(i, k) <= r; ++i) {
            if (f(i, k) >= l)
                ans++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}