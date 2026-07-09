#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N=1e9+7;
    int divisibleGame(vector<int>& nums) {
        int n=nums.size(),mx=ranges::max(nums);
        ll cha=-1,k=2;
        vector<bool>vis(mx+1);
        vector<int>prime;
        for (int i = 2; i <= mx; ++i) {
            if (!vis[i])
                prime.push_back(i);
            for (auto &j: prime){
                if (i*j>mx) break;
                vis[i*j]=1;
                if (i%j==0) break;
            }
        }
        for (auto &j: prime){
            ll mn=0,pre=0;
            for (int i = 0; i < n; ++i) {
                mn=min(mn,pre);
                pre+=nums[i]%j==0?nums[i]:-nums[i];
                if (pre-mn>cha){
                    cha=pre-mn;
                    k=j;
                }
            }
        }
        return (cha*k+N)%N;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}