#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,ans=0,n=s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i]=='(') {
                cnt++;
                ans=max(ans,cnt);
            }else if (s[i]==')') {
                cnt--;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}