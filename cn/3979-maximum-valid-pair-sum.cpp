#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxValidPairSum(vector<int> &nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = max(pre[i], nums[i]);
        }
        for (int i = k + 1; i <= n; ++i) {
            ans = max(ans, pre[i - k] + nums[i - 1]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}