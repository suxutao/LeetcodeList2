#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        auto check = [&](long long m) -> bool {
            long long cnt = 0;
            for (int i = 1; i < (1 << coins.size()); i++) {
                long long lcm_res = 1;
                for (int j = 0; j < coins.size(); j++) {
                    if (i >> j & 1) {
                        lcm_res = lcm(lcm_res, coins[j]);
                        if (lcm_res > m) {
                            break;
                        }
                    }
                }
                cnt += popcount(1u * i) % 2 ? m / lcm_res : -m / lcm_res;
            }
            return cnt >= k;
        };

        long long left = k - 1, right = 1LL * ranges::min(coins) * k;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}