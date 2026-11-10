#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        vector<int>ans,cnt(k);
        set<int>se;
        priority_queue<array<int,2>,vector<array<int,2>>,greater<>>q;
        for (int i = 0; i < k; ++i) {
            se.insert(i);
        }
        for (int i = 0; i < n; ++i) {
            while (!q.empty()&&q.top()[0]<=arrival[i]) {
                se.insert(q.top()[1]);
                q.pop();
            }
            if (se.empty())
                continue;
            auto it = se.lower_bound(i%k);
            if (it==se.end()) {
                it=se.begin();
            }
            q.push({arrival[i]+load[i],*it});
            cnt[*it]++;
            se.erase(*it);
        }
        int mx=0;
        for (int i = 0; i < k; ++i) {
            if (cnt[i]>mx) {
                mx=cnt[i];
                ans.clear();
                ans.push_back(i);
            }else if (cnt[i]==mx) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}