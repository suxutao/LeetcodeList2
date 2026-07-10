#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumSaleItems(vector<vector<int>> &items, int budget) {
        int n = items.size(), mn = INT_MAX, ans = 0;
        vector<int> cnt_factor(n + 1);
        vector<int> cnt_sum(n + 1);
        vector<array<int, 2>> v;
        for (auto &i: items) {
            mn = min(mn, i[1]);
            cnt_factor[i[0]]++;
        }
        for (auto &i: items) {
            if (i[1] >= mn * 2)
                continue;
            auto &sum = cnt_sum[i[0]];
            if (sum == 0) {
                for (int j = i[0]; j <= n; j += i[0]) {
                    sum += cnt_factor[j];
                }
            }
            if (sum > 1)
                v.push_back({i[1], sum - 1});
        }
        ranges::sort(v);
        for (auto &[price, cnt]: v) {
            if (budget < price)
                break;
            int c = min(cnt, budget / price);
            ans += c * 2;
            budget -= c * price;
        }
        return ans + budget / mn;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}