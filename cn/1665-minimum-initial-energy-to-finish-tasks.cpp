#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int p=0,ans=0;
        ranges::sort(tasks,[&](auto&a,auto&b)->bool{
            return a[1]-a[0]>b[1]-b[0];
        });
        for (auto &i: tasks){
            if (i[1]<=p){
                p-=i[0];
            }else{
                ans+=i[1]-p;
                p=i[1]-i[0];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}