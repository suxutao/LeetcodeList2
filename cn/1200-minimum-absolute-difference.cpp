#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size(),mn=INT_MAX;
        vector<vector<int>>ans;
        ranges::sort(arr);
        for (int i = 1; i < n; ++i) {
            if (arr[i]-arr[i-1]<mn){
                ans.clear();
                mn=arr[i]-arr[i-1];
                ans.push_back({arr[i-1],arr[i]});
            }else if (arr[i]-arr[i-1]==mn){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}