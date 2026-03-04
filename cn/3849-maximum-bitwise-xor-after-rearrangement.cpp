#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string maximumXor(string s, string t) {
        int a0=0,a1=0,n=t.size();
        string ans(n,'0');
        for (int i = 0; i < n; ++i) {
            if (t[i]=='0'){
                ++a0;
            }else{
                ++a1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s[i]=='0'){
                if (a1>0){
                    --a1;
                    ans[i]='1';
                }else{
                    --a0;
                }
            }else{
                if (a0>0){
                    --a0;
                    ans[i]='1';
                }else{
                    --a1;
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}