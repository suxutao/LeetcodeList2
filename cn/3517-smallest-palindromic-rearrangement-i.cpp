#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string ans=s.substr(0,n/2);
        ranges::sort(ans,greater<>());
        string ans_r=ans;
        ranges::reverse(ans);
        if (n&1)
            return ans+s.substr(n/2,1)+ans_r;
        else
            return ans+ans_r;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}