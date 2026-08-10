#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int stoneGameII(vector<int> &piles) {
        int n = piles.size(), sum = 0;
        vector<vector<int>> dp(n, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; --i) {
            sum += piles[i];
            for (int j = 1; j <= i / 2 + 1; ++j) {
                if (i + j * 2 >= n) {
                    dp[i][j] = sum;
                } else {
                    for (int k = 1; k <= j * 2; ++k) {
                        dp[i][j] = max(dp[i][j], sum - dp[i + k][max(j, k)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}