#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string sortVowels(string s) {
        int n=s.size(),tt=0;
        string t;
        unordered_set<char>se{'a','e','i','o','u'};
        unordered_map<int,int>pos,cnt;
        for (int i = 0; i < n; ++i) {
            if (se.contains(s[i])){
                if (!pos.contains(s[i])){
                    pos[s[i]]=i;
                }
                cnt[s[i]]++;
                t.push_back(s[i]);
            }
        }
        ranges::sort(t,[&](auto&a,auto&b)->bool{
            if (cnt[a]==cnt[b])
                return pos[a]<pos[b];
            return cnt[a]>cnt[b];
        });
        for (int i = 0; i < n; ++i) {
            if (se.contains(s[i])){
                s[i]=t[tt++];
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}