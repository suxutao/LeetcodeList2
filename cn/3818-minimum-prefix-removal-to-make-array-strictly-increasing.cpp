#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        for (int i = n - 1; i; --i) {
            if (nums[i]<=nums[i-1])
                return i;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}