#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size(),mx=0,sum=0;
        for (int i = 0; i < n; ++i) {
            mx=max(mx,nums[i]);
            sum+=nums[i];
        }
        return mx*n-sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}