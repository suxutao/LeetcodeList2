#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double dis(vector<int>&a,vector<int>&b){
        return sqrt((double)(a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
    }
    double f(double a,double b,double c){
        double p=(a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double ans=0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                for (int k = j+1; k < n; ++k) {
                    if (points[i][0]==points[j][0]&&points[i][0]==points[k][0]||points[i][1]==points[j][1]&&points[i][1]==points[k][1])
                        continue;
                    ans= max(ans,f(dis(points[i],points[j]), dis(points[i], points[k]), dis(points[j],points[k])));
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}