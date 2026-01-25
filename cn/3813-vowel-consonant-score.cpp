#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int vowelConsonantScore(string s) {
        int n=s.size(),v=0,c=0;
        unordered_set<char>se{'a','e','i','o','u'};
        for (int i = 0; i < n; ++i) {
            if (se.contains(s[i])){
                ++v;
            }else if (s[i]>='a'&&s[i]<='z'){
                ++c;
            }
        }
        return c==0?0:v/c;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}