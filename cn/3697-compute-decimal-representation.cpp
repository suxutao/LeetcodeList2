#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        long long chen=1;
        vector<int>ans;
        while (n){
            ans.push_back(n%10*chen);
            if (ans.back()==0)
                ans.pop_back();
            chen*=10;
            n/=10;
        }
        ranges::reverse(ans);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}