#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int n=s.size(),l=0;
        set<char>ans;
        unordered_map<char,int>m;
        map<int,set<char>>ms;
        for (int i = 0; i < n; ++i) {
            ++m[s[i]];
        }
        for (auto &[a,b]: m){
            ms[b].insert(a);
        }
        for (auto &[a,b]: ms){
            if (b.size()>=l){
                l=b.size();
                ans=b;
            }
        }
        return string (ans.begin(),ans.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}