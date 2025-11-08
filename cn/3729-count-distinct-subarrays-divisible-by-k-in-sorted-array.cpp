#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long numGoodSubarrays(vector<int>& nums, int k) {
        ll ans=0,sum=0,n=nums.size();
        unordered_map<int,int>m,t;
        m[0]=1;
        nums.insert(nums.begin(),nums[0]);
        for (int i = 1; i <= n; ++i) {
            if (nums[i]!=nums[i-1]){
                for (auto &[s,cnt]: t){
                    m[s]+=cnt;
                }
                t.clear();
            }
            sum=(sum+nums[i])%k;
            ans+=m[sum];
            t[sum]++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<int>v{1,2,3};
    Solution().numGoodSubarrays(v,3);
    return 0;
}