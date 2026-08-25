#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int> > findDisappearedNumbers(vector<int> &nums, int lower, int upper) {
        int n = nums.size(), l = lower, r = lower - 1;
        unordered_set<int> s;
        vector<vector<int> > ans;
        for (int i = 0; i < n; ++i) {
            s.insert(nums[i]);
        }
        for (int i = lower; i <= upper; ++i) {
            if (s.contains(i)) {
                if (l != i && l <= r) {
                    ans.push_back({l, r});
                }
                l = i + 1;
                r = i;
            } else {
                r++;
            }
        }
        if (l <= r) {
            ans.push_back({l, r});
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
