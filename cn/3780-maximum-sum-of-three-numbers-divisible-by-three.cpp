#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumSum(vector<int> &nums) {
        int n = nums.size(), ans = 0;
        array<vector<int>, 3> a;
        ranges::sort(nums, greater<>());
        for (int i = 0; i < n; ++i) {
            a[nums[i] % 3].push_back(nums[i]);
        }
        for (int i = 0; i < 3; ++i) {
            if (a[i].size() > 2)
                ans = max(ans, a[i][0] + a[i][1] + a[i][2]);
        }
        if (!a[0].empty() && !a[1].empty() && !a[2].empty())
            ans = max(ans, a[0][0] + a[1][0] + a[2][0]);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}