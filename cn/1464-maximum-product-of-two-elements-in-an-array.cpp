#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ranges::sort(nums,greater<>());
        return (nums[0]-1)*(nums[1]-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}