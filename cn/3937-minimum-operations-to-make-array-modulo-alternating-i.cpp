#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int dis(int k, int real, int target) {
        return min((real - target + k) % k, (target - real + k) % k);
    }

    int minOperations(vector<int> &nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        if (n == 1)
            return 0;
        for (int i = 0; i < n; ++i) {
            nums[i] %= k;
        }
        for (int i = 0; i < k; ++i) {
            for (int l = 0; l < k; ++l) {
                if (i == l)
                    continue;
                int to = 0, tj = 0;
                for (int j = 0; j < n; j += 2) {
                    to += dis(k, nums[j], i);
                }
                for (int j = 1; j < n; j += 2) {
                    tj += dis(k, nums[j], l);
                }
                ans = min(ans, to + tj);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}