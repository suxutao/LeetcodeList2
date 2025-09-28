#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    int fa[100005]{};
    int find_set(int x){
        return fa[x]==x?x:fa[x]= find_set(fa[x]);
    }
    void merge_set(int x,int y){
        x= find_set(x);
        y= find_set(y);
        if (x!=y)
            fa[x]=y;
    }
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        ll n=nums.size(),ans=0;
        unordered_map<int,vector<int>>m;
        unordered_map<int,int>z;
        for (int i = 0; i < n; ++i) {
            fa[i]=i;
        }
        for (auto &i: swaps){
            merge_set(i[0],i[1]);
        }
        for (int i = 0; i < n; ++i) {
            int t=find_set(i);
            m[t].push_back(nums[i]);
            if (i%2==0)
                z[t]++;
        }
        for (auto &[f,v]: m){
            ranges::sort(v,greater<>());
            for (int i = 0; i < z[f]; ++i) {
                ans+=v[i];
            }
            for (int i = z[f]; i < v.size(); ++i) {
                ans-=v[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}