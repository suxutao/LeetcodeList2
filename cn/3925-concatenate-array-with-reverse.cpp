#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> concatWithReverse(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n * 2);
        for (int i = 0; i < n; ++i) {
            ans[i] = ans[n * 2 - i - 1] = nums[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}