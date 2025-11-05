#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        multiset<double> L, R;
        vector<double> ans(n - k + 1);
        auto add = [&](double x) {
            if (L.empty() || x <= *L.rbegin()) {
                L.insert(x);
            } else {
                R.insert(x);
            }
        };
        auto del = [&](double x) {
            if (R.contains(x)) {
                R.extract(x);
            } else {
                L.extract(x);
            }
        };
        auto l2r = [&]() {
            int t = *L.rbegin();
            R.insert(t);
            L.extract(t);
        };
        auto r2l = [&]() {
            int t = *R.begin();
            L.insert(t);
            R.extract(t);
        };
        for (int i = 0; i < k; ++i) {
            L.insert(nums[i]);
        }
        while (L.size() > (k + 1) / 2)
            l2r();
        ans[0] = k & 1 ? *L.rbegin() : (*L.rbegin() + *R.begin()) / 2.;
        for (int i = k; i < n; ++i) {
            add(nums[i]);
            del(nums[i - k]);
            while (L.size() > (k + 1) / 2)
                l2r();
            while (L.size() < (k + 1) / 2)
                r2l();
            ans[i - k + 1] = k & 1 ? *L.rbegin() : (*L.rbegin() + *R.begin()) / 2.;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}