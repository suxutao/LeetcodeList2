#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxOperations(string s) {
        int ans=0,pre=s[0]=='1',n=s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i]=='1'){
                pre++;
            }else if (s[i]!=s[i-1]){
                ans+=pre;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}