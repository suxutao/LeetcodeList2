#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long maxSubarraySum(vector<int> &nums, long long k) {
        int n = nums.size();
        long long f0 = nums[0], f1 = nums[0] * k, f2 = nums[0] / k, f3 = nums[0], ans = max(f1, f2);
        for (int i = 1; i < n; ++i) {
            f3 = max({f0, f1, f2, f3, 0ll}) + nums[i];
            f1 = max({f0, f1, 0ll}) + nums[i] * k;
            f2 = max({f0, f2, 0ll}) + nums[i] / k;
            f0 = max(f0, 0ll) + nums[i];
            ans = max(ans, max({f0, f1, f2, f3}));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}