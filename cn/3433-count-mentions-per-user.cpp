#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events) {
        unordered_map<int, int> m;
        vector<int> ans(numberOfUsers);
        ranges::sort(events, [&](auto &a, auto &b) {
            int na = stoi(a[1]), nb = stoi(b[1]);
            if (na==nb)
                return a[0]>b[0];
            return na<nb;
        });
        for (auto &v: events) {
            if (v[0] == "MESSAGE") {
                if (v[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        ans[i]++;
                    }
                } else if (v[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (!m.contains(i) || stoi(v[1]) >= m[i])
                            ans[i]++;
                    }
                } else {
                    stringstream ss(v[2]);
                    string temp;
                    while (getline(ss, temp, ' ')) {
                        ans[stoi(temp.substr(2))]++;
                    }
                }
            } else {
                m[stoi(v[2])] = stoi(v[1]) + 60;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}