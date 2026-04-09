#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    const int MOD = 1'000'000'007;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(queries.size());
        vector<vector<int>> diff(B);

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            long long v = q[3];
            if (k < B) {
                // 懒初始化
                if (diff[k].empty()) {
                    diff[k].resize(n + k, 1);
                }
                diff[k][l] = diff[k][l] * v % MOD;
                r = r - (r - l) % k + k;
                diff[k][r] = diff[k][r] * pow(v, MOD - 2) % MOD;
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = nums[i] * v % MOD;
                }
            }
        }

        for (int k = 1; k < B; k++) {
            auto& d = diff[k];
            if (d.empty()) {
                continue;
            }
            for (int start = 0; start < k; start++) {
                long long mul_d = 1;
                for (int i = start; i < n; i += k) {
                    mul_d = mul_d * d[i] % MOD;
                    nums[i] = nums[i] * mul_d % MOD;
                }
            }
        }

        return reduce(nums.begin(), nums.end(), 0, bit_xor());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}