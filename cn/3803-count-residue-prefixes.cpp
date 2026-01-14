#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int residuePrefixes(string s) {
        int n=s.size(),ans=0;
        unordered_set<char>se;
        for (int i = 1; i <= n; ++i) {
            se.insert(s[i-1]);
            if (se.size()>3)
                break;
            if (se.size()==i%3)
                ans++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}