#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    vector<ll> distance(vector<int>& nums) {
        int n=nums.size();
        vector<ll>ans(n);
        unordered_map<int,vector<ll>>m;
        for (int i = 0; i < n; ++i) {
            m[nums[i]].push_back(i);
        }
        for (auto &[a,v]: m){
            ll nv=v.size(),pre=0;
            vector<ll>suf(nv);
            for (int i = nv-2; i >= 0; --i) {
                suf[i]=suf[i+1]+(v[i+1]-v[i])*(nv-i-1);
            }
            ans[v[0]]=suf[0];
            for (int i = 1; i < nv; ++i) {
                pre+=(v[i]-v[i-1])*i;
                ans[v[i]]=pre+suf[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}