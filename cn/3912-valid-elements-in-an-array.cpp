#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findValidElements(vector<int> &nums) {
        int n = nums.size(), pre = nums[0];
        vector<int> ans, suf(n + 1);
        ans.push_back(nums[0]);
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = max(suf[i + 1], nums[i]);
        }
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > pre || nums[i] > suf[i + 1])
                ans.push_back(nums[i]);
            pre = max(nums[i], pre);
        }
        if (n > 1)
            ans.push_back(nums[n - 1]);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}