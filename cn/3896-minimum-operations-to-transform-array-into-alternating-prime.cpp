#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(vector<int> &nums) {
        int mx = 100003, n = nums.size(), ans = 0;
        vector<int> prime;
        vector<bool> is_prime(mx, 1);
        is_prime[1] = 0;
        for (int i = 2; i <= mx; ++i) {
            if (is_prime[i]) prime.push_back(i);
            for (auto j: prime) {
                if (i * j > mx) break;
                is_prime[i * j] = 0;
                if (i % j == 0) break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                if (is_prime[nums[i]]) {
                    if (nums[i] == 2)
                        ans += 2;
                    else
                        ans++;
                }
            } else {
                if (!is_prime[nums[i]]) {
                    int it = *upper_bound(prime.begin(), prime.end(), nums[i]);
                    ans += it - nums[i];
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}