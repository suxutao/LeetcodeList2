#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countValidPrefixes(string s) {
        int zero=0,n=s.size(),ans=0;
        for (int i = 0; i < n; ++i) {
            if (s[i]=='0')
                zero++;
            ans+=abs(i+1-zero*2)<=1;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}