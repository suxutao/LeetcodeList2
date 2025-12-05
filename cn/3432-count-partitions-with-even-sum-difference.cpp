#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPartitions(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        return sum & 1 ? 0 : n - 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}