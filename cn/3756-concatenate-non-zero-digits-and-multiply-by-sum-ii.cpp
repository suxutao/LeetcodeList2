#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>Sum(n+1),p(n+1),ans;
        vector<ll>pre(n+1),ten(n+1);
        ten[0]=1;
        for (int i = 1; i <= n; ++i) {
            Sum[i]=Sum[i-1]+s[i-1]-'0';
            ten[i]=ten[i-1]*10%N;
            if (s[i-1]=='0'){
                pre[i]=pre[i-1];
                p[i]=p[i-1];
            }else{
                pre[i]=(pre[i-1]*10+s[i-1]-'0')%N;
                p[i]=p[i-1]+1;
            }
        }
        for (auto &i: queries){
            ll sum=(Sum[i[1]+1]-Sum[i[0]]+N)%N;
            ll x=(pre[i[1]+1]-pre[i[0]]*ten[p[i[1]+1]-p[i[0]]]%N+N)%N;
            ans.push_back(sum*x%N);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}