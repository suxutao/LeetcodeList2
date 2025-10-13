#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string>ans{words[0]};
        string pre=words[0];
        ranges::sort(pre);
        for (int i = 1; i < n; ++i) {
            string t=words[i];
            ranges::sort(t);
            if (t!=pre)
                ans.push_back(words[i]);
            pre=t;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}