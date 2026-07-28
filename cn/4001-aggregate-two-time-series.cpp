#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n1=series1.size(),n2=series2.size(),p1=0,p2=0;
        vector<vector<int>>ans;
        while (p1<n1&&p2<n2){
            if (series1[p1][0]<series2[p2][0]){
                ans.push_back(series1[p1]);
                auto pos=lower_bound(series2.begin(), series2.end(),vector<int>{series1[p1][0],0});
                if (pos!=series2.end()){
                    ans.back()[1]+=(*pos)[1];
                }
                p1++;
            }else if (series1[p1][0]>series2[p2][0]){
                ans.push_back(series2[p2]);
                auto pos=lower_bound(series1.begin(), series1.end(),vector<int>{series2[p2][0],0});
                if (pos!=series1.end()){
                    ans.back()[1]+=(*pos)[1];
                }
                p2++;
            }else{
                ans.push_back({series1[p1][0],series1[p1][1]+series2[p2][1]});
                p1++;p2++;
            }
        }
        while (p1<n1){
            ans.push_back(series1[p1]);
            p1++;
        }
        while (p2<n2){
            ans.push_back(series2[p2]);
            p2++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}