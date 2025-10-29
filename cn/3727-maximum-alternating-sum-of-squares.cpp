#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long maxAlternatingSum(vector<int> &nums) {
        ll ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] = abs(nums[i]);
        }
        ranges::sort(nums, greater<>());
        for (int i = 0; i < (n + 1) / 2; ++i) {
            ans += nums[i] * nums[i];
        }
        for (int i = (n + 1) / 2; i < n; ++i) {
            ans -= nums[i] * nums[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}