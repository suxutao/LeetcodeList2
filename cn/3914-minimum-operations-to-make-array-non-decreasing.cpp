#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long minOperations(vector<int>& nums) {
        ll ans=0,n=nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i]<nums[i-1]){
                ans+=nums[i-1]-nums[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}