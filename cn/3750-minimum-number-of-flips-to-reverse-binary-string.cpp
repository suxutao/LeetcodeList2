#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumFlips(int n) {
        int ans=0;
        string s,t;
        while (n){
            s.push_back(n&1?'1':'0');
            n>>=1;
        }
        t=s;
        ranges::reverse(t);
        for (int i = 0; i < s.size(); ++i) {
            ans+=t[i]!=s[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}