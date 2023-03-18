#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;
typedef pair<int, int> PII;
vector<PII> intervals;

int main() {
    vector<PII> res;
    PII temp;
    int n;
    cin >> n;

    while (n --) {
        int l , r;
        cin >> l >> r;
        intervals.push_back({l, r});
    }

    sort(intervals.begin(), intervals.end());

    temp.first = intervals[0].first;
    temp.second = intervals[0].second;
    for (int i = 1; i < intervals.size(); i ++) {
        if (intervals[i].first <= temp.second) {
            temp.second = max(intervals[i].second, temp.second);
        } else {
            res.push_back(temp);
            temp.first = intervals[i].first;
            temp.second = intervals[i].second;
        }
    }
    res.push_back(temp);

    cout << res.size() << endl;
}