#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size(),ans=0;
        priority_queue<int,vector<int>,greater<>>q;
        q.push(neededTime[0]);
        for (int i = 1; i < n; ++i) {
            if (colors[i]==colors[i-1]){
                q.push(neededTime[i]);
            }else{
                while (q.size()>1)
                    ans+=q.top(),q.pop();
                q.pop();
                q.push(neededTime[i]);
            }
        }
        while (q.size()>1)
            ans+=q.top(),q.pop();
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}