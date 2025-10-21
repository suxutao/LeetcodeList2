#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations) {
        int n = nums.size(), l = 0, r = 0, ans = 0;
        unordered_map<int, int> m;
        ranges::sort(nums);
        nums.push_back(INT_MAX);
        for (int &x: nums) {
            ++m[x];
        }
        for (int i = nums[0]; i <= nums[n - 1]; ++i) {
            while (nums[r] - i <= k)
                ++r;
            while (i - nums[l] > k)
                ++l;
            ans = max(ans, m[i] + min(numOperations, r - l - m[i]));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}