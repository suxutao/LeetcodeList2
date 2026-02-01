#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseByType(string s) {
        int n=s.size();
        string ans(n,'a');
        vector<array<int,2>>v,b;
        for (int i = 0; i < n; ++i) {
            if (s[i]>='a'&&s[i]<='z'){
                v.push_back({i, s[i]});
            }else{
                b.push_back({i, s[i]});
            }
        }
        int nv=v.size(),nb=b.size();
        for (int i = 0; i < nv; ++i) {
            ans[v[i][0]]=v[nv-i-1][1];
        }
        for (int i = 0; i < nb; ++i) {
            ans[b[i][0]]=b[nb-i-1][1];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}