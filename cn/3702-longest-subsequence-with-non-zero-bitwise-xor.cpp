#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size(),x_or=0;
        long long sum=0;
        for (int i = 0; i < n; ++i) {
            x_or^=nums[i];
            sum+=nums[i];
        }
        if (sum==0)
            return 0;
        return x_or?n:n-1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}