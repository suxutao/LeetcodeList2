#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i]==2) {
                ans[i]=-1;
            }else{
                int j;
                for (j = 0; (nums[i]>>j)&1; ++j) {}
                ans[i]=nums[i]^(1<<(j-1));
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}