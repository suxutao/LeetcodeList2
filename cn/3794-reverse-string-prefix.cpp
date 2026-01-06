#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reversePrefix(string s, int k) {
        string t=s.substr(0,k);
        ranges::reverse(t);
        return t+s.substr(k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}