#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int arr[4][2]{{0,1},{1,0},{0,-1},{-1,0}};
        if (grid[0][0]||grid[n-1][n-1])
            return 0;
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        vector<vector<int>>Dis(n,vector<int>(n,INT_MAX));
        queue<array<int,2>>q;
        priority_queue<array<int,3>>pq;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int cnt=1;
        while (!q.empty()){
            int sz=q.size();
            for (int i = 0; i < sz; ++i) {
                auto[x,y]=q.front();
                q.pop();
                for (auto [a,b]: arr){
                    a+=x;b+=y;
                    if (a>=0&&a<n&&b>=0&&b<n&&dis[a][b]==INT_MAX){
                        dis[a][b]=cnt;
                        q.push({a,b});
                    }
                }
            }
            cnt++;
        }
        Dis[0][0]=0;
        pq.push({dis[0][0],0,0});
        while (!pq.empty()){
            auto [d,x,y]=pq.top();
            pq.pop();
            if (x==n-1&&y==n-1)
                return d;
            for (auto [a,b]: arr){
                a+=x;b+=y;
                if (a>=0&&a<n&&b>=0&&b<n){
                    int nd=min(d,dis[a][b]);
                    if (nd<Dis[a][b]){
                        Dis[a][b]=nd;
                        pq.push({nd,a,b});
                    }
                }
            }
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}