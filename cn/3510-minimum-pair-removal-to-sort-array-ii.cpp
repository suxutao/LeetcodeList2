#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        set<pair<long long, int>> pairs; // (相邻元素和，左边那个数的下标)
        int dec = 0; // 递减的相邻对的个数
        for (int i = 0; i + 1 < n; i++) {
            int x = nums[i], y = nums[i + 1];
            if (x > y) {
                dec++;
            }
            pairs.emplace(x + y, i);
        }

        set<int> idx; // 剩余下标
        for (int i = 0; i < n; i++) {
            idx.insert(i);
        }

        vector<long long> a(nums.begin(), nums.end());
        int ans = 0;
        while (dec > 0) {
            ans++;

            // 删除相邻元素和最小的一对
            auto [s, i] = *pairs.begin();
            pairs.erase(pairs.begin());

            auto it = idx.lower_bound(i);

            // (当前元素，下一个数)
            auto nxt_it = next(it);
            int nxt = *nxt_it;
            dec -= a[i] > a[nxt]; // 旧数据

            // (前一个数，当前元素)
            if (it != idx.begin()) {
                int pre = *prev(it);
                dec -= a[pre] > a[i]; // 旧数据
                dec += a[pre] > s; // 新数据
                pairs.erase({a[pre] + a[i], pre});
                pairs.emplace(a[pre] + s, pre);
            }

            // (下一个数，下下一个数)
            auto nxt2_it = next(nxt_it);
            if (nxt2_it != idx.end()) {
                int nxt2 = *nxt2_it;
                dec -= a[nxt] > a[nxt2]; // 旧数据
                dec += s > a[nxt2]; // 新数据（当前元素，下下一个数）
                pairs.erase({a[nxt] + a[nxt2], nxt});
                pairs.emplace(s + a[nxt2], i);
            }

            a[i] = s; // 把 a[nxt] 加到 a[i] 中
            idx.erase(nxt); // 删除 nxt
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}