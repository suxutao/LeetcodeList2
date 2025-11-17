#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n=s.size(),n1=0,n2=0;
        for (int i = 0; i < n; ++i) {
            if (s[i]=='a')
                ++n1;
            else
                ++n2;
        }
        return abs(n1-n2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}