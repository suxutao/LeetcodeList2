#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool scoreBalance(string s) {
        int sum=0,n=s.size(),x=0;
        for (int i = 0; i < n; ++i) {
            sum+=s[i]-'a'+1;
        }
        if (sum&1)
            return false;
        for (int i = 0; i < n; ++i) {
            x+=s[i]-'a'+1;
            if (x*2==sum)
                return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}