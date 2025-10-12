#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class ExamTracker {
public:
    using ll = long long;
    vector<array<ll, 2>> pre,arr;

    ExamTracker() {
        pre.push_back({0, 0});
    }

    void record(int time, int score) {
        arr.push_back({time,score});
        pre.push_back({time, score + pre.back()[1]});
    }

    long long totalScore(int startTime, int endTime) {
        int start = lower_bound(arr.begin(), arr.end(), (array<ll, 2>) {startTime}) - arr.begin();
        int end = lower_bound(arr.begin(), arr.end(), (array<ll, 2>) {endTime+1}) - arr.begin();
        return pre[end][1]-pre[start][1];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}