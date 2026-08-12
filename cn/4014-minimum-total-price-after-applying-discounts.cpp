#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double minPrice(vector<int> &prices, vector<int> &discounts) {
        int m = prices.size(), n = discounts.size();
        double ans = 0;
        ranges::sort(prices, greater<>());
        ranges::sort(discounts, greater<>());
        for (int i = 0; i < m; ++i) {
            if (i < n) {
                ans += prices[i] * (100 - discounts[i]) / 100.;
            } else {
                ans += prices[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}