#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool pan(vector<int>&v){
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i]>v[i+1])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0,n=nums.size();
        for (int i = 0; i < n-1; ++i) {
            if (pan(nums)){
                break;
            }
            int sum=INT_MAX,pos=0;
            for (int j = 0; j < nums.size()-1; ++j) {
                if (nums[j]+nums[j+1]<sum){
                    sum=nums[j]+nums[j+1];
                    pos=j;
                }
            }
            nums.erase(nums.begin()+pos,nums.begin()+pos+2);
            nums.insert(nums.begin()+pos,sum);
            ans++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<int>v{2,2,-1,3,-2,2,1,1,1,0,-1};
    Solution().minimumPairRemoval(v);
    return 0;
}