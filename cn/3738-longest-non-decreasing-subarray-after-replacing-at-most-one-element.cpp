#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),pre=1,ans=1;
        vector<int>suf(n,1);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i]<=nums[i+1]){
                suf[i]=suf[i+1]+1;
            }
        }
        for (int i = 1; i < n-1; ++i) {
            if (nums[i-1]<=nums[i+1]){
                ans=max(ans,pre+suf[i+1]+1);
            }else{
                ans=max(ans,max(pre+1,suf[i+1]+1));
            }
            if (nums[i]>=nums[i-1]){
                pre++;
            }else{
                pre=1;
            }
        }
        ans=max(ans,max(pre+1,suf[1]+1));
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}