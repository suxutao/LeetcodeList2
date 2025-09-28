#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n=s.size();
        set<pair<int,int>>se;
        int f['Z']{};
        for (int i = 0; i < k; ++i) {
            ++f[s[i]];
        }
        se.insert({f['L']-f['R'],f['U']-f['D']});
        for (int i = k; i < n; ++i) {
            --f[s[i-k]];
            ++f[s[i]];
            se.insert({f['L']-f['R'],f['U']-f['D']});
        }
        return se.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}