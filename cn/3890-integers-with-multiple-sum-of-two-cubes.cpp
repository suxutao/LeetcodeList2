#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int sz= ceil(cbrt(n));
        vector<int>v(sz+1),ans;
        unordered_map<int,int>m;
        for (int i = 1; i <= sz; ++i) {
            v[i]=i*i*i;
        }
        for (int i = 1; i <= sz; ++i) {
            for (int j = i+1; j <= sz; ++j) {
                if (v[i]+v[j]<=n){
                    ++m[v[i]+v[j]];
                    if (m[v[i]+v[j]]==2)
                        ans.push_back(v[i]+v[j]);
                }else{
                    break;
                }
            }
        }
        ranges::sort(ans);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}