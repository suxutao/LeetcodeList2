#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>v(n);
        set<int>s;
        priority_queue<array<ll,2>,vector<array<ll,2>>,greater<>>q;
        for (int i = 0; i < n; ++i) {
            s.insert(i);
        }
        ranges::sort(meetings);
        for (auto &i: meetings){
            while (!q.empty()&&q.top()[0]<=i[0]){
                s.insert(q.top()[1]);
                q.pop();
            }
            if (s.empty()){
                v[q.top()[1]]++;
                q.push({q.top()[0]+i[1]-i[0],q.top()[1]});
                q.pop();
            }else{
                v[*s.begin()]++;
                q.push({i[1],*s.begin()});
                s.erase(s.begin());
            }
        }
        int ans=0,mx=0;
        for (int i = 0; i < n; ++i) {
            if (v[i]>mx){
                mx=v[i];
                ans=i;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}