#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MovieRentingSystem {
public:
    unordered_map<int,unordered_map<int,int>>m,info;
    unordered_map<int,priority_queue<array<int,2>,vector<array<int,2>>,greater<>>>mq;
    priority_queue<array<int,3>,vector<array<int,3>>,greater<>>q;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &i: entries){
            m[i[1]][i[0]]=i[2];
            mq[i[1]].push({i[2],i[0]});
        }
        info=m;
    }
    
    vector<int> search(int movie) {
        vector<int>ans;
        vector<array<int,2>>t;
        int sz=mq[movie].size();
        for (int i = 0; i < sz && ans.size()<5; ++i) {
            auto [price,shop]=mq[movie].top();
            if (~m[movie][shop]){
                if (ans.empty()||ans.back()!=shop){
                    ans.push_back(shop);
                    t.push_back({price,shop});
                }
            }
            mq[movie].pop();
        }
        for (auto &item: t)
            mq[movie].push(item);
        return ans;
    }
    
    void rent(int shop, int movie) {
        q.push({m[movie][shop],shop,movie});
        m[movie][shop]=-1;
    }
    
    void drop(int shop, int movie) {
        m[movie][shop]=info[movie][shop];
        mq[movie].push({m[movie][shop],shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        vector<array<int,3>>t;
        int sz=q.size();
        for (int i = 0; i < sz && ans.size() < 5; ++i) {
            auto [price,shop,movie]=q.top();
            q.pop();
            if (m[movie][shop]==-1){
                if (ans.empty()||ans.back()[0]!=shop||ans.back()[1]!=movie){
                    ans.push_back({shop, movie});
                    t.push_back({price, shop, movie});
                }
            }
        }
        for (auto &item: t)
            q.push(item);
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<vector<int>>entries{{0,1,5},{0,2,6}, {0,3,7},{1,1,4},{1,2,7},{2,1,5}};
    MovieRentingSystem* obj = new MovieRentingSystem(3, entries);
    vector<int> param_1 = obj->search(1);
    return 0;
}