#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int>ji,ou;
            for (int j = i; j < n; ++j) {
                if (nums[j]&1)
                    ji.insert(nums[j]);
                else
                    ou.insert(nums[j]);
                if (ji.size()==ou.size())
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}