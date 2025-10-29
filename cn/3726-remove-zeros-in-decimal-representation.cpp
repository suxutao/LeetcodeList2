#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long removeZeros(long long n) {
        string s=to_string(n);
        ll ans=0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]>'0'){
                ans=ans*10+s[i]-'0';
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}