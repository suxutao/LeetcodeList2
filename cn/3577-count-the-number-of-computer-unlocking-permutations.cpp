#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const int N=1e9+7;
    using ll = long long;
    int countPermutations(vector<int>& complexity) {
        int qi=complexity[0],n=complexity.size();
        ll ans=1;
        for (int i = 1; i < n; ++i) {
            if (complexity[i]<=qi)
                return 0;
        }
        for (int i = 2; i <= n - 1; ++i) {
            ans=ans*i%N;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}