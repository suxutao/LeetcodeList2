#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long maxSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<ll> pre(n + 1), dp(n + 1, LLONG_MIN);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
        for (int i = k; i <= n; ++i) {
            dp[i] = max(dp[i - k], 0ll) + pre[i] - pre[i - k];
        }
        return *max_element(dp.begin() + 1, dp.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}