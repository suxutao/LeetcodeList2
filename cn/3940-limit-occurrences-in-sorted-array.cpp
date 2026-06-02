#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> limitOccurrences(vector<int> &nums, int k) {
        int n = nums.size(), count = 1;
        vector<int> v{nums[0]};
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                if (count + 1 <= k) {
                    count++;
                    v.push_back(nums[i]);
                }
            } else {
                count = 1;
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}