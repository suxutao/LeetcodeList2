#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size(),l=0,r=0,ans=0;
        for (int i = 0; i < n; ++i) {
            if (s[i]=='(') {
                l++;
            }else {
                if (i==n-1||s[i+1]!=')') {
                    ans++;
                }else {
                    i++;
                }
                r++;
                if (r>l) {
                    l++;
                    ans++;
                }
            }
        }
        return ans+(l-r)*2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}