#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size(),nq=queries.size();
        vector<int>pre(n+1),ans(nq);
        for (int i = 0; i < n; ++i) {
            pre[i+1]=pre[i]^arr[i];
        }
        for (int i = 0; i < nq; ++i) {
            auto&j=queries[i];
            ans[i]=pre[j[1]+1]^pre[j[0]];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}