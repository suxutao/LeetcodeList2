#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long minimumTime(vector<int>& d, vector<int>& r) {
        ll L=1,R=(1ll<<53)-2,mid;
        auto check=[&](ll x)->bool {
            ll t1=x-x/r[0],t2=x-x/r[1],t3=x-(x/r[0]+x/r[1]-x/((ll)r[0]*r[1]/gcd(r[0],r[1]))),d1=d[0],d2=d[1];
            t1-=t3;t2-=t3;
            d1-=t1;d2-=t2;
            if (d1>0)
                t3-=d1;
            if (d2>0)
                t3-=d2;
            return t3>=0;
        };
        while (L<R){
            mid=(L+R)>>1;
            if (!check(mid)){
                L=mid+1;
            }else{
                R=mid;
            }
        }
        return L;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}