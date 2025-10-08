#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeSubstring(string s, int k) {
        int n=s.size();
        string ans;
        vector<pair<int,char>>v;
        for (int i = 0; i < n; ++i) {
            if (v.empty()||s[i]!=v.back().second){
                v.push_back({1,s[i]});
            }else{
                v.back().first++;
            }
            if (s[i]==')'&&v.size()>=2){
                if (v[v.size()-1].first==k&&v[v.size()-2].first>=k){
                    v.pop_back();
                    v.back().first-=k;
                    if (v.back().first==0)
                        v.pop_back();
                }
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            ans+=string(v[i].first,v[i].second);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}