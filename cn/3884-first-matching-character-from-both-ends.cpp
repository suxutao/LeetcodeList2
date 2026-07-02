#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstMatchingIndex(string s) {
        int n=s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i]==s[n-i-1])
                return i;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}