#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size(), l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[0] <= target || target < nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}