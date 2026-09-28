#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        string ans,t;
        unordered_map<string,string>m;
        for (auto&k:knowledge) {
            m[k[0]]=k[1];
        }
        for (int i = 0; i < n; ++i) {
            if (s[i]=='(') {
                t.clear();
                for (int j = 1; i+j < n; ++j) {
                    if (s[i+j]==')') {
                        i+=j;
                        break;
                    }
                    t.push_back(s[i+j]);
                }
                ans+=m.contains(t)?m[t]:"?";
            }else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}