#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0,n=nums.size(),pre=0;
        for (int i = 2; i < n; ++i) {
            if (nums[i]==nums[i-1]+nums[i-2]){
                pre++;
            }else{
                pre=0;
            }
            ans=max(ans,pre);
        }
        return ans+2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}