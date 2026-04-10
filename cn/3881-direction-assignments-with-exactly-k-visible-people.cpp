#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N=1e9+7;
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
    int countVisiblePeople(int n, int pos, int k) {
        vector<ll>f(n),inv(n);
        f[0]=1;inv[0]=1;
        for (int i = 1; i < n; ++i) {
            f[i]=f[i-1]*i%N;
            inv[i]=fast(f[i],N-2);
        }
        return 2*f[n-1]*inv[k]%N*inv[n-1-k]%N;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}