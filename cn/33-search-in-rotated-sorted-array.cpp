#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int f(vector<int> &v, int l, int r, int target) {
        int mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (v[mid] == target)
                return mid;
            else if (v[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return -1;
    }

    int search(vector<int> &nums, int target) {
        int n = nums.size(), l = 0, r = n - 1, mid, pos;
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        if (nums[0] < nums[n - 1])
            return f(nums, 0, n, target);
        while (l < r) {
            mid = (l + r) >> 1;
            if (nums[mid] > nums[mid + 1]) {
                pos = mid;
                break;
            } else if (nums[mid] > nums[0]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int f1 = f(nums, 0, pos + 1, target);
        int f2 = f(nums, pos, n, target);
        if (f1 == -1 && f2 == -1)
            return -1;
        else if (f1 != -1)
            return f1;
        else
            return f2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}