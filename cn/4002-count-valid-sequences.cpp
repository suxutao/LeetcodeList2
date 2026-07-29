#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const int N=1e9+7;
    using ll = long long;
    ll fast(ll a,ll x){
        ll ans=1;
        while (x){
            if (x&1)
                ans=ans*a%N;
            a=a*a%N;
            x>>=1;
        }
        return ans;
    }
    int countValidSequences(int n, int k) {
        vector<ll>v(n+1);
        v[0]=1;
        for (int i = 1; i <= n; ++i) {
            v[i]=i*v[i-1]%N;
        }
        ll ans=v[n-1]*fast(v[k-1],N-2)%N*fast(v[n-k],N-2)%N;
        if ((n+k)%2==0){
            ll t=(n+k)/2;
            ans=(ans+N-v[t-1]*fast(v[k-1],N-2)%N*fast(v[t-k],N-2)%N)%N;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}