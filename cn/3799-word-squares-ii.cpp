#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n=words.size();
        vector<vector<string>>vvs;
        ranges::sort(words);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j==i)
                    continue;
                for (int k = 0; k < n; ++k) {
                    if (k==i||k==j)
                        continue;
                    for (int l = 0; l < n; ++l) {
                        if (l==i||l==j||l==k)
                            continue;
                        if (words[i][0]==words[j][0]&&words[i][3]==words[k][0]&&words[l][0]==words[j][3]&&words[l][3]==words[k][3])
                            vvs.push_back({words[i],words[j],words[k],words[l]});
                    }
                }
            }
        }
        return vvs;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}