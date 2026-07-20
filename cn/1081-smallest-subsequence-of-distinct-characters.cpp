#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        string ans;
        unordered_map<char,int>m;
        unordered_set<char>se;
        for (int i = 0; i < n; ++i) {
            ++m[s[i]];
        }
        for (int i = 0; i < n; ++i) {
            --m[s[i]];
            if (se.contains(s[i]))
                continue;
            while (!ans.empty()&&m[ans.back()]>0&&s[i]<ans.back()){
                se.erase(ans.back());
                ans.pop_back();
            }
            ans.push_back(s[i]);
            se.insert(s[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}