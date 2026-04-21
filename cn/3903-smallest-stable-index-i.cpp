#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstStableIndex(vector<int> &nums, int k) {
        int n = nums.size(), mx = 0;
        vector<int> mn(n + 1);
        mn[n] = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            mn[i] = min(mn[i + 1], nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            if (mx - mn[i] <= k)
                return i;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}