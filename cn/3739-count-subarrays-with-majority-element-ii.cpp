#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
using ll = long long;
struct FenwickTree{
    int n;
    vector<int>tree;
    FenwickTree(int n):tree(n+1),n(n){}

    void add(int x,int d){
        while (x<=n){
            tree[x]+=d;
            x+=x&-x;
        }
    }

    ll pre(int x){
        ll ans=0;
        while (x>0){
            ans+=tree[x];
            x-=x&-x;
        }
        return ans;
    }

    ll query(int l,int r){
        return pre(r)-pre(l-1);
    }
};
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ll n=nums.size(),ans=0;
        vector<int>pre(n+1);
        for (int i = 0; i < n; ++i) {
            pre[i+1]=pre[i]+(nums[i]==target?1:-1);
        }
        ll mn=ranges::min(pre),offset=1-mn,mx=offset+ranges::max(pre);
        FenwickTree tree(mx+1);
        tree.add(pre[0]+offset,1);
        for (int i = 1; i <= n; ++i) {
            ans+=tree.pre(pre[i]+offset-1);
            tree.add(pre[i]+offset,1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}