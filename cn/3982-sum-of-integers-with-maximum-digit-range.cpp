#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int f(int x){
        int mn=9,mx=0;
        while (x){
            mx=max(mx,x%10);
            mn=min(mn,x%10);
            x/=10;
        }
        return mx-mn;
    }
    int maxDigitRange(vector<int>& nums) {
        int ans=0,n=nums.size(),mx=0;
        for (int i = 0; i < n; ++i) {
            int x= f(nums[i]);
            if (x>mx){
                mx=x;
                ans=nums[i];
            }else if (x==mx){
                ans+=nums[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}