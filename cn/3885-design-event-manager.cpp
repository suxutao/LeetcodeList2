#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class EventManager {
public:
    unordered_map<int,int>m;
    priority_queue<array<int,2>>q;
    unordered_set<long long>s;
    EventManager(vector<vector<int>>& events) {
        for (auto &i: events){
            m[-i[0]]=i[1];
            q.push({i[1],-i[0]});
            s.insert((long long)i[0]<<32|i[1]);
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if (m[-eventId]!=newPriority){
            m[-eventId]=newPriority;
            if (!s.contains((long long)eventId<<32|newPriority)){
                q.push({newPriority,-eventId});
                s.insert((long long)eventId<<32|newPriority);
            }
        }
    }
    
    int pollHighest() {
        while (!q.empty()&&m[q.top()[1]]!=q.top()[0]){
            s.erase((long long)(-q.top()[1])<<32|q.top()[0]);
            q.pop();
        }
        if (q.empty())
            return -1;
        int ans=-q.top()[1];
        s.erase((long long)(-q.top()[1])<<32|q.top()[0]);
        q.pop();
        return ans;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}