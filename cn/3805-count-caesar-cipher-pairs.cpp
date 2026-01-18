#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,int>s;
        int n=words.size(),m=words[0].size();
        long long ans=0;
        for (int i = 0; i < n; ++i) {
            int cha=words[i][0]-'a';
            words[i][0]='a';
            for (int j = 1; j < m; ++j) {
                words[i][j]-=cha;
                if (words[i][j]<'a')
                    words[i][j]+=26;
            }
            ans+=s[words[i]]++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}