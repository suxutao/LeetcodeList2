#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size(),sum=accumulate(nums.begin(), nums.end(),0),t=0,ans=0;
        for (int i = 0; i < n; ++i) {
            t+=nums[i];
            if (nums[i]==0){
                if (t*2==sum)
                    ans+=2;
                else if (abs(sum-t*2)==1)
                    ans++;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}