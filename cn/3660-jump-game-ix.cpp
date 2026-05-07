#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size(),mx=0,suf=nums[n-1];
        vector<int>ans(n),pre(n+1);
        for (int i = 0; i < n; ++i) {
            pre[i+1]=max(pre[i],nums[i]);
            mx=max(mx,nums[i]);
        }
        ans[n-1]=mx;
        for (int i = n - 2; i >= 0; --i) {
            if (pre[i+1]<=suf){
                ans[i]=pre[i+1];
            }else{
                ans[i]=ans[i+1];
            }
            suf=min(suf,nums[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}