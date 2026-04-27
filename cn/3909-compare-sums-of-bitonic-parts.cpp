#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int compareBitonicSums(vector<int> &nums) {
        long long add = 0, minus = 0, n = nums.size(), da = 0;
        if (n == 1)
            return -1;
        if (nums[1] > nums[0]) {
            add += nums[0];
            da = 1;
        } else {
            minus += nums[0];
        }
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                add += nums[i];
                if (da == 0) {
                    da = 1;
                    add += nums[i - 1];
                }
            } else {
                minus += nums[i];
                if (da == 1) {
                    da = 0;
                    minus += nums[i - 1];
                }
            }
        }
        if (add > minus)
            return 0;
        else if (add < minus)
            return 1;
        else
            return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}