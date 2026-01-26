#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>>g;
    vector<int>vx,vy,vz;
    bool pan(long long a,long long b,long long c){
        vector<long long>v{a,b,c};
        ranges::sort(v);
        return v[0]*v[0]+v[1]*v[1]==v[2]*v[2];
    }
    void dfs(vector<int>&v,int u,int fa,int dis){
        v[u]=dis;
        for (auto &i: g[u]){
            if (i==fa)
                continue;
            dfs(v,i,u,dis+1);
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        int ans=0;
        g.resize(n);
        vx.resize(n);
        vy.resize(n);
        vz.resize(n);
        for (auto &i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        dfs(vx,x,x,0);
        dfs(vy,y,y,0);
        dfs(vz,z,z,0);
        for (int i = 0; i < n; ++i) {
            ans+=pan(vx[i],vy[i],vz[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}