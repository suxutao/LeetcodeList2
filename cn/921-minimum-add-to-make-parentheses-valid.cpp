#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size(),l=0,r=0,ans=0;
        for (int i = 0; i < n; ++i) {
            if (s[i]=='(') {
                ++l;
            }else {
                ++r;
                if (r>l) {
                    ++l;
                    ++ans;
                }
            }
        }
        return ans+l-r;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}