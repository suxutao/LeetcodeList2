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
    int numberOfSets(int n, int k) {
        vector<ll>jie(n+k);
        jie[0]=jie[1]=1;
        for (int i = 2; i < n+k; ++i) {
            jie[i]=i*jie[i-1]%N;
        }
        return jie[n+k-1]*fast(jie[2*k],N-2)%N*fast(jie[n-k-1],N-2)%N;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}