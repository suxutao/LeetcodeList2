#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    using pii = pair<int, int>;
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        ll n=nums.size(),sum=0;
        set<pii>L,R;
        unordered_map<int,int>m;
        vector<ll>ans(n-k+1);
        auto add=[&](int t){
            pii p={m[t],t};
            if (p.first==0)
                return;
            if (!L.empty()&&p>*L.begin()){
                sum+=(ll)p.first*p.second;
                L.insert(p);
            }else{
                R.insert(p);
            }
        };
        auto del=[&](int t){
            pii p={m[t],t};
            if (p.first==0)
                return;
            if (L.contains(p)){
                sum-=(ll)p.first*p.second;
                L.erase(p);
            }else{
                R.erase(p);
            }
        };
        auto l2r=[&](){
            pii p=*L.begin();
            sum-=(ll)p.first*p.second;
            R.insert(p);
            L.erase(p);
        };

        auto r2l=[&](){
            pii p=*R.rbegin();
            sum+=(ll)p.first*p.second;
            L.insert(p);
            R.erase(p);
        };

        for (int i = 0; i < k; ++i) {
            del(nums[i]);
            ++m[nums[i]];
            add(nums[i]);
        }
        while (L.size()>x)
            l2r();
        while (!R.empty()&&L.size()<x)
            r2l();
        ans[0]=sum;
        for (int i = k; i < n; ++i) {
            int in=nums[i],out=nums[i-k];
            del(in);
            ++m[in];
            add(in);
            del(out);
            --m[out];
            add(out);

            while (L.size()>x)
                l2r();
            while (!R.empty()&&L.size()<x)
                r2l();
            ans[i-k+1]=sum;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}