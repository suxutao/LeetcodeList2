#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const int N = 1e9 + 7;
    using ll = long long;
    int gg[151][151]{};

    int countCoprime(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        if (m == 1)
            return count(mat[0].begin(), mat[0].end(), 1);
        vector<ll> dp(n + 1), arr(151);
        for (int i = 1; i <= 150; ++i) {
            for (int j = 1; j <= 150; ++j) {
                gg[i][j] = gcd(i, j);
            }
        }
        for (int i = 0; i < n; ++i) {
            ++arr[mat[0][i]];
        }
        for (int i = 1; i < m; ++i) {
            vector<ll> t(151);
            for (int j = 1; j <= n; ++j) {
                dp[j] = dp[j - 1];
                for (int k = 1; k <= 150; ++k) {
                    if (gg[k][mat[i][j - 1]] == 1)
                        dp[j] = (dp[j] + arr[k]) % N;
                    t[gg[k][mat[i][j - 1]]] = (t[gg[k][mat[i][j - 1]]] + arr[k]) % N;
                }
            }
            arr = t;
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}