#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N = 1e9 + 7;

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

    int minimumCost(vector<int>& nums, int k) {
        ll sum = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        if (sum <= k)
            return 0;
        ll add = (ll)ceil((double)(sum - k) / k) % N;
        return add % N * (add + 1) % N * fast(2, N - 2) % N;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}