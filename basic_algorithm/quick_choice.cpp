#include <iostream>

using namespace std;

const int N = 100010;

int n, k;
int q[N];

int quick_choice(int l, int r, int k) {
    if (l == r) return q[l];

    int pilot = q[l];
    int i = l - 1, j = r + 1;

    while (i < j) {
        while (q[++i] < pilot);
        while (q[--j] > pilot);
        if (i < j) swap(q[i], q[j]);
    }

    // decide to use quick sort in which side.
    int len = j - l + 1;
    if (k <= len) return quick_choice(l, j, k);
    return quick_choice(j + 1, r, k - len);
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> q[i];

    cout << quick_choice(0, n - 1, k) << endl;

    return 0;
}