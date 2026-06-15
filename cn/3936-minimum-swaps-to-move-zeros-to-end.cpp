#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size(),ans=0,cnt=0;
        for (int i = 0; i < n; ++i) {
            cnt+=nums[i]==0;
        }
        for (int i = 0; i < cnt; ++i) {
            if (nums[n-1-i])
                ans++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}