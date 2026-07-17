#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries) {
        int n = nums.size(), mx = ranges::max(nums);
        vector<int> ans, cnt(mx + 1);
        vector<ll> v(mx + 1);
        for (int i = 0; i < n; ++i) {
            cnt[nums[i]]++;
        }
        for (int i = mx; i; --i) {
            int t = 0;
            for (int j = i; j <= mx; j += i) {
                t += cnt[j];
                v[i] -= v[j];
            }
            v[i] += (ll) t * (t - 1) / 2;
        }
        for (int i = 1; i <= mx; ++i) {
            v[i] += v[i - 1];
        }
        for (auto &i: queries) {
            int pos = upper_bound(v.begin(), v.end(), i) - v.begin();
            ans.push_back(pos);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}