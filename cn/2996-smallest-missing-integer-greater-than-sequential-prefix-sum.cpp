#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int missingInteger(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        while (find(s.begin(), s.end(), sum) != s.end()) {
            sum++;
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}