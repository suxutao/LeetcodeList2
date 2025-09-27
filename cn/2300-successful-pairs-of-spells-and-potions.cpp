#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        vector<int>ans(n);
        ranges::sort(potions);
        for (int i = 0; i < n; ++i) {
            int p= lower_bound(potions.begin(), potions.end(),ceil((double)success/spells[i]))-potions.begin();
            ans[i]=potions.size()-p;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}