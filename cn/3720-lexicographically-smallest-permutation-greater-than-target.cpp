#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        sort(s.begin(), s.end(), greater<>());
        if (s <= target)
            return "";
        for (int i = 0; i < n; ++i) {
            vector<int> v[26];
            for (int l = i; l < n; ++l) {
                v[s[l] - 'a'].push_back(l);
            }
            for (int j = target[i] - 'a'; j < 26; ++j) {
                if (!v[j].empty()) {
                    swap(s[i], s[v[j].back()]);
                    string t=s;
                    sort(t.begin() + i + 1, t.end(), greater<>());
                    if (s[i]==target[i]&&t.substr(i + 1) <= target.substr(i + 1)) {
                        swap(s[i], s[v[j].back()]);
                        for (int k = j + 1; k < 26; ++k) {
                            if (!v[k].empty()) {
                                swap(s[i], s[v[k].back()]);
                                sort(s.begin() + i + 1, s.end());
                                return s;
                            }
                        }
                    } else {
                        v[j].pop_back();
                        break;
                    }
                }
            }
            if (s[i]>target[i]){
                sort(s.begin() + i + 1, s.end());
                return s;
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution().lexGreaterPermutation("kq", "iq");
    return 0;
}