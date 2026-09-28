#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N=1e9+7;
    ll fast(ll a,ll x) {
        ll ans=1;
        while (x) {
            if (x&1)
                ans=ans*a%N;
            a=a*a%N;
            x>>=1;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        ll ans=0;
        for (auto xy:nums) {
            ll width=xy%10,d=xy/10;
            string s=to_string(d);
            ll x=stoll(s.substr(0,width));
            ll y=stoll(s.substr(width));
            ans=(ans+fast(x,y))%N;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}