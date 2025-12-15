#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseWords(string s) {
        int cnt=-1;
        string ans,t;
        stringstream ss(s);
        unordered_set<char>se{'a','e','i','o','u'};
        while (getline(ss,t,' ')){
            if (~cnt){
                int tc=0;
                ans.push_back(' ');
                for (int i = 0; i < t.size(); ++i) {
                    tc+=se.contains(t[i]);
                }
                if (tc==cnt){
                    ranges::reverse(t);
                }
                ans+=t;
            }else{
                cnt=0;
                for (int i = 0; i < t.size(); ++i) {
                    cnt+=se.contains(t[i]);
                }
                ans+=t;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}