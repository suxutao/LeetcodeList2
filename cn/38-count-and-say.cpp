#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string countAndSay(int n) {
        string s="1",temp;
        for (int i = 0; i < n-1; ++i) {
            char c;
            int p=0,cnt;
            while (p<s.size()){
                c=s[p];cnt=0;
                while (p<s.size()&&s[p]==c)
                    ++p,++cnt;
                temp+=to_string(cnt);
                temp.push_back(c);
            }
            s.swap(temp);
            temp.clear();
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution().countAndSay(2);
    return 0;
}