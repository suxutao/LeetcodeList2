#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int stoneGameVIII(vector<int> &stones) {
        int n = stones.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += stones[i];
        }
        int dp = sum;
        for (int i = n - 2; i > 0; --i) {
            sum -= stones[i + 1];
            dp = max(dp, sum - dp);
        }
        return dp;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
