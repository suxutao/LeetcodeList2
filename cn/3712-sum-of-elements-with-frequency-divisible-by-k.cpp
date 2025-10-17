#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        unordered_map<int,int>m;
        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];
        }
        for (auto &[a,b]: m){
            if (b%k==0)
                ans+=a*b;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}