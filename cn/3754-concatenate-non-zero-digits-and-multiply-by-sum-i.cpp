#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long sumAndMultiply(int n) {
        ll x=0,sum=0;
        string s=to_string(n);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]!='0'){
                sum+=s[i]-'0';
                x=x*10+s[i]-'0';
            }
        }
        return sum*x;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}