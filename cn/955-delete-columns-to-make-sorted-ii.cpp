#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<string> a(n);
        int ans = 0;
        for (int j = 0; j < m; j++) {
            bool del = false;
            for (int i = 0; i < n - 1; i++) {
                if (a[i] + strs[i][j] > a[i + 1] + strs[i + 1][j]) {
                    ans++;
                    del = true;
                    break;
                }
            }
            if (!del) {
                for (int i = 0; i < n; i++) {
                    a[i] += strs[i][j];
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}