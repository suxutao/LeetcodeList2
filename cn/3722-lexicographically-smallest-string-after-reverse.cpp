#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string ans=s;
        for (int i = 2; i < n; ++i) {
            string qian=s.substr(0,i);
            string hou=s.substr(i);
            ranges::reverse(qian);
            ans=min(ans,qian+hou);
        }
        for (int i = 0; i < n; ++i) {
            string qian=s.substr(0,i);
            string hou=s.substr(i);
            ranges::reverse(hou);
            ans=min(ans,qian+hou);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}