#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();
        ll sum=accumulate(nums.begin(), nums.begin()+dist+2,0ll);
        multiset<int>L,R;
        --k;
        auto l2r=[&](){
            int x=*L.rbegin();
            L.extract(x);
            sum-=x;
            R.insert(x);
        };
        auto r2l=[&](){
            int x=*R.begin();
            R.extract(x);
            sum+=x;
            L.insert(x);
        };
        for (int i = 1; i <= dist+1; ++i) {
            L.insert(nums[i]);
        }
        while (L.size()>k)
            l2r();

        ll ans=sum;
        for (int i = dist+2; i < n; ++i) {
            int out=nums[i-dist-1];
            if (L.contains(out)){
                L.extract(out);
                sum-=out;
            }else{
                R.extract(out);
            }

            if (nums[i]<*L.rbegin()){
                L.insert(nums[i]);
                sum+=nums[i];
            }else{
                R.insert(nums[i]);
            }

            if (L.size()==k-1)
                r2l();
            else if (L.size()==k+1)
                l2r();
            ans= min(ans,sum);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}