#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size(),m=ranges::max(nums);
        const int N=1e9+7;
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(m+1,vector<int>(m+1,-1)));

        auto dfs=[&](this auto&&dfs,int i,int j,int k)->int{
            if (i<0)
                return j==k;
            int&x=memo[i][j][k];
            if (x==-1){
                x=((long long)dfs(i-1,j,k)+dfs(i-1,gcd(j,nums[i]),k)+dfs(i-1,j,gcd(nums[i],k)))%N;
            }
            return x;
        };
        return dfs(n-1,0,0)-1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}