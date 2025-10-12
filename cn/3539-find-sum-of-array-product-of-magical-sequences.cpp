#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
const int MOD = 1'000'000'007;
const int MX = 31;

long long F[MX]; // F[i] = i!
long long INV_F[MX]; // INV_F[i] = i!^-1

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

auto init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = pow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--) {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
}();

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        vector pow_v(n, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            pow_v[i][0] = 1;
            for (int j = 1; j <= m; j++) {
                pow_v[i][j] = 1LL * pow_v[i][j - 1] * nums[i] % MOD;
            }
        }

        vector memo(n, vector(m + 1, vector(m / 2 + 1, vector<int>(k + 1, -1))));
        auto dfs = [&](this auto&& dfs, int i, int left_m, int x, int left_k) -> int {
            int c1 = popcount((uint32_t) x);
            if (c1 + left_m < left_k) { // 可行性剪枝
                return 0;
            }
            if (i == n || left_m == 0 || left_k == 0) { // 无法继续选数字
                return left_m == 0 && c1 == left_k;
            }
            int& res = memo[i][left_m][x][left_k]; // 注意这里是引用
            if (res != -1) {
                return res;
            }
            res = 0;
            for (int j = 0; j <= left_m; j++) { // 枚举 I 中有 j 个下标 i
                // 这 j 个下标 i 对 S 的贡献是 j * pow(2, i)
                // 由于 x = S >> i，转化成对 x 的贡献是 j
                int bit = (x + j) & 1; // 取最低位，提前从 left_k 中减去，其余进位到 x 中
                int r = dfs(i + 1, left_m - j, (x + j) >> 1, left_k - bit);
                res = (res + 1LL * r * pow_v[i][j] % MOD * INV_F[j]) % MOD;
            }
            return res;
        };
        return 1LL * dfs(0, m, 0, k) * F[m] % MOD;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}