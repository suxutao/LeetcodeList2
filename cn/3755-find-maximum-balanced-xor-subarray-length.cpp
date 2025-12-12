#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    int maxBalancedSubarray(vector<int> &nums) {
        int n = nums.size(), ans = 0, pxor = 0, pre = n;
        unordered_map<ll, int> m;
        m[n]=-1;
        for (int i = 0; i < n; ++i) {
            pxor ^= nums[i];
            if (nums[i] & 1) {
                pre++;
            } else {
                pre--;
            }
            ll key = (ll) pxor << 32 | pre;
            if (m.contains(key)) {
                ans = max(ans, i - m[key]);
            } else {
                m[key] = i;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}