#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<long long>v(n),pre(n),suf(n);
        vector<int>ans;
        v[0]=1;v[n-1]=n-2;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i]-nums[i-1]<=nums[i+1]-nums[i]){
                v[i]=i-1;
            }else{
                v[i]=i+1;
            }
        }
        for (int i = 0; i < n-1; ++i) {
            if (v[i]==i+1){
                pre[i+1]=pre[i]+1;
            }else{
                pre[i+1]=pre[i]+nums[i+1]-nums[i];
            }
        }
        for (int i = n - 1; i; --i) {
            if (v[i]==i-1){
                suf[i-1]=suf[i]+1;
            }else{
                suf[i-1]=suf[i]+nums[i]-nums[i-1];
            }
        }
        for (auto &q: queries){
            if (q[0]<=q[1]){
                ans.push_back(pre[q[1]]-pre[q[0]]);
            }else{
                ans.push_back(suf[q[1]]-suf[q[0]]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}