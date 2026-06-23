#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans(m,string(n,'#'));
        for (int i = 0; i < m; ++i) {
            ans[i][0]='.';
        }
        for (int i = 0; i < n; ++i) {
            ans[m-1][i]='.';
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}