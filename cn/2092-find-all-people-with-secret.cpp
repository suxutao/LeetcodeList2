#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct union_set{
    vector<int>fa;
    union_set(int n):fa(n+1){
        for (int i = 0; i < n; ++i) {
            fa[i]=i;
        }
    }
    int find_set(int x){
        return fa[x]==x?x:fa[x]= find_set(fa[x]);
    }

    void merge_set(int x,int y){
        x= find_set(x);
        y= find_set(y);
        if (x!=y)
            fa[y]=x;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int ns=meetings.size();
        union_set unse(n);
        unse.merge_set(0,firstPerson);
        ranges::sort(meetings,[&](auto&a,auto&b){
            return a[2]<b[2];
        });
        for (int i = 0; i < ns; ) {
            int start=i,end=i;
            while (end<ns&&meetings[start][2]==meetings[end][2]){
                unse.merge_set(meetings[end][0],meetings[end][1]);
                end++;
            }
            for (int j = start; j < end; ++j) {
                if (unse.find_set(meetings[j][0])!=unse.find_set(0)){
                    unse.fa[meetings[j][0]]=meetings[j][0];
                }
                if (unse.find_set(meetings[j][1])!=unse.find_set(0)){
                    unse.fa[meetings[j][1]]=meetings[j][1];
                }
            }
            i=end;
        }
        vector<int>ans;
        for (int i = 0; i < n; ++i) {
            if (unse.find_set(i)==unse.find_set(0))
                ans.push_back(i);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}