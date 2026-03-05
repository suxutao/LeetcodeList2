#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n=costs.size(),ans=0;
        vector<array<int,2>>v;
        stack<array<int,2>>s;
        s.push({0,0});
        for (int i = 0; i < n; ++i) {
            if(costs[i]<budget)
                v.push_back({costs[i],capacity[i]});
        }
        ranges::sort(v);
        for (int i = 0; i < v.size(); ++i) {
            while (s.top()[0]+v[i][0]>=budget){
                s.pop();
            }
            ans=max(ans,v[i][1]+s.top()[1]);
            if (s.top()[1]<v[i][1]) {
                s.push(v[i]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}