#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int q=queries.size(),d=dictionary.size(),n=queries[0].size();
        vector<string>ans;
        for (int i = 0; i < q; ++i) {
            for (int j = 0; j < d; ++j) {
                int cnt=0;
                for (int k = 0; k < n; ++k) {
                    cnt+=queries[i][k]!=dictionary[j][k];
                }
                if (cnt<=2) {
                    ans.push_back(queries[i]);
                    break;
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