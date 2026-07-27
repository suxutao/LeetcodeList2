#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        ranges::sort(nums);
        for (int i = 0; i < n - 2; ++i) {
            if (i&&nums[i]==nums[i-1]) continue;
            if (nums[i]+nums[i+1]+nums[i+2]>0) break;
            if (nums[i]+nums[n-1]+nums[n-2]<0) continue;
            int j=i+1,k=n-1;
            while (j<k){
                if (nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    ++j;--k;
                    while (j<k&&nums[j]==nums[j-1]) ++j;
                    while (j<k&&nums[k]==nums[k+1]) --k;
                }else if (nums[i]+nums[j]+nums[k]<0){
                    ++j;
                }else{
                    --k;
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}