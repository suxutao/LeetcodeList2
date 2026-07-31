#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<array<ll,2>>>dis(m+1,vector<array<ll,2>>(n+1, {LLONG_MAX,LLONG_MAX}));
        priority_queue<tuple<ll,int,int,int>,vector<tuple<ll,int,int,int>>,greater<>>q;
        q.emplace(1,1,1,0);
        dis[1][1][0]=1;
        while (!q.empty()){
            auto [price,x,y,cnt]=q.top();
            if (x==m&&y==n)
                return price;
            q.pop();
            if (x>1){
                ll d=price+(x-1)*y+(cnt?0:penalty[x-1][y-1]);
                if (d<dis[x-1][y][cnt]){
                    dis[x-1][y][cnt]=d;
                    q.emplace(d,x-1,y,1-cnt);
                }
            }
            if (y>1){
                ll d=price+(y-1)*x+(cnt?0:penalty[x-1][y-1]);
                if (d<dis[x][y-1][cnt]){
                    dis[x][y-1][cnt]=d;
                    q.emplace(d,x,y-1,1-cnt);
                }
            }
            if (x<m){
                ll d=price+(x+1)*y+(cnt?penalty[x-1][y-1]:0);
                if (d<dis[x+1][y][cnt]){
                    dis[x+1][y][cnt]=d;
                    q.emplace(d,x+1,y,1-cnt);
                }
            }
            if (y<n){
                ll d=price+(y+1)*x+(cnt?penalty[x-1][y-1]:0);
                if (d<dis[x][y+1][cnt]){
                    dis[x][y+1][cnt]=d;
                    q.emplace(d,x,y+1,1-cnt);
                }
            }
            price+=penalty[x-1][y-1];
            cnt=1-cnt;
            if (price<dis[x][y][cnt])
                dis[x][y][cnt]=price;
            if (x>1){
                ll d=price+(x-1)*y+(cnt?0:penalty[x-1][y-1]);
                if (d<dis[x-1][y][cnt]){
                    dis[x-1][y][cnt]=d;
                    q.emplace(d,x-1,y,1-cnt);
                }
            }
            if (y>1){
                ll d=price+(y-1)*x+(cnt?0:penalty[x-1][y-1]);
                if (d<dis[x][y-1][cnt]){
                    dis[x][y-1][cnt]=d;
                    q.emplace(d,x,y-1,1-cnt);
                }
            }
            if (x<m){
                ll d=price+(x+1)*y+(cnt?penalty[x-1][y-1]:0);
                if (d<dis[x+1][y][cnt]){
                    dis[x+1][y][cnt]=d;
                    q.emplace(d,x+1,y,1-cnt);
                }
            }
            if (y<n){
                ll d=price+(y+1)*x+(cnt?penalty[x-1][y-1]:0);
                if (d<dis[x][y+1][cnt]){
                    dis[x][y+1][cnt]=d;
                    q.emplace(d,x,y+1,1-cnt);
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