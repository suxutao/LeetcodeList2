#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool hui(string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }

    vector<int> minOperations(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n), v;
        for (int i = 1; i <= 6000; ++i) {
            int t = i;
            string s;
            while (t) {
                s.push_back((t & 1) + '0');
                t >>= 1;
            }
            if (hui(s))
                v.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            auto pos = lower_bound(v.begin(), v.end(), nums[i]);
            ans[i] = abs(nums[i] - *pos);
            if (pos != v.begin())
                ans[i] = min(ans[i], abs(nums[i] - *prev(pos)));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}