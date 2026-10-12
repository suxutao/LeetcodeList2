#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N = 1e9 + 7;

    int maxSum(vector<int> &nums, int k) {
        ll ans = 0;
        int n = nums.size(), arr[32]{};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 32; ++j) {
                if (nums[i] >> j & 1) {
                    arr[j]++;
                }
            }
        }
        for (int i = 0; i < k; ++i) {
            ll x = 0;
            for (int j = 31; j >= 0; --j) {
                if (arr[j]) {
                    x += 1 << j;
                    arr[j]--;
                }
            }
            ans = (ans + x * x % N) % N;
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
