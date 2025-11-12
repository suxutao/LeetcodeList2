#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),g=gcd(nums[0],nums[1]),dis=n-2,mn=min(nums[0],nums[1]);
        for (int i = 2; i < n; ++i) {
            g=gcd(g,nums[i]);
            mn=min(mn,nums[i]);
        }
        if (g>1)
            return -1;
        for (int i = 0; i < n; ++i) {
            g=0;
            for (int j = i; j < n; ++j) {
                g=gcd(g,nums[j]);
                if (g==1){
                    dis=min(dis,j-i-1);
                    break;
                }
            }
        }
        return mn==1?n-count(nums.begin(), nums.end(),1):dis+n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}