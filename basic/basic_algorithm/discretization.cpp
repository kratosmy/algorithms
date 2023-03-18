  #include <iostream>
  #include <vector>
  #include <algorithm>

  using namespace std;

  typedef pair<int, int> PII;

  const int N = 300010;

  int n, m;
  int a[N], s[N];

  vector<int> all;
  vector<PII> query, add;

  int find(int x) {
    int l = 0, r = all.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (all[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
  }

  // define your own unique function
  vector<int>::iterator unique(vector<int>& a) {
    int j = 0;
    for (int i = 0; i < a.size(); i ++) {
      if (!i || a[i] != a[i - 1]) {
        a[j ++] = a[i];
      }
    }
    return a.begin() + j;
  }

  int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        all.push_back(x);
    }

    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        all.push_back(l);
        all.push_back(r);
    }

    // 去重
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    // insert
    for (auto& item : add) {
        int y = find(item.first);
        a[y] += item.second;
    }

    // prefix sum
    for (int i = 1; i <= all.size(); i ++) s[i] = s[i - 1] + a[i];

    // handle query
    for (auto& item : query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
  }