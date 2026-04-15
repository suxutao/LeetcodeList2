#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDigitOccurrences(vector<int> &nums, int digit) {
        int ans = 0;
        for (auto i: nums) {
            while (i) {
                ans += digit == i % 10;
                i /= 10;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}