#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans=INT_MAX,n=nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[i]==1&&nums[j]==2){
                    ans=min(ans,abs(i-j));
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}