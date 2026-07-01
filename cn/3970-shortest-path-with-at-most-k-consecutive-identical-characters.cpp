#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>>dis(n,vector<int>(k+1,INT_MAX));
        vector<vector<array<int,2>>>g(n);
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>>q;
        for (auto &i: edges){
            g[i[0]].push_back({i[1],i[2]});
        }
        dis[0][1]=0;
        q.push({0,0,1});
        while (!q.empty()){
            auto [d,node,cnt]=q.top();
            q.pop();
            if (node==n-1)
                return d;
            for (auto &[to,w]: g[node]){
                int new_cnt=labels[node]==labels[to]?cnt+1:1;
                if (new_cnt>k) continue;
                if (d+w<dis[to][new_cnt]){
                    dis[to][new_cnt]=d+w;
                    q.push({d+w,to,new_cnt});
                }
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}