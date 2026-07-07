#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int m=s.size(),n=t.size(),pp=0,ps=m-1;
        vector<int>pre(m,-1),suf(m,-1);
        for (int i = 0; i < n; ++i) {
            if (pp<m&&t[i]==s[pp]){
                pre[pp++]=i;
            }
        }
        if (~pre[m-1])
            return true;
        for (int i = n - 1; i >= 0; --i) {
            if (ps>=0&&t[i]==s[ps]){
                suf[ps--]=i;
            }
        }
        if(m==1||~suf[1]&&suf[1]||~pre[m-2]&&pre[m-2]!=n-1){
            return true;
        }
        for (int i = 1; i < m - 1; ++i) {
            if (~pre[i-1]&&~suf[i+1]&&pre[i-1]<suf[i+1]-1)
                return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}