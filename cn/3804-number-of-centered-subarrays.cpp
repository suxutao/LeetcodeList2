#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int>pre(n+1);
        for (int i = 0; i < n; ++i) {
            pre[i+1]=pre[i]+nums[i];
            for (int j = 0; j <= i; ++j) {
                int sum=pre[i+1]-pre[j];
                for (int k = j; k <= i; ++k) {
                    if (nums[k]==sum){
                        ans++;
                        break;
                    }
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