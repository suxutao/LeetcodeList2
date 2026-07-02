#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(),n=grid[0].size();
        int arr[4][2]{{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>>q;
        dis[0][0]=grid[0][0];
        q.push({grid[0][0],0,0});
        while (!q.empty()){
            auto [h,x,y]=q.top();
            if (x==m-1&&y==n-1){
                return h<health;
            }
            q.pop();
            for (auto [a,b]: arr){
                a+=x;b+=y;
                if (a>=0&&a<m&&b>=0&&b<n&&h+grid[a][b]<dis[a][b]){
                    dis[a][b]=h+grid[a][b];
                    q.push({dis[a][b],a,b});
                }
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}