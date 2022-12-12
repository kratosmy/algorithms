#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> &A, int b) {
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

int main() {
    string a;
    vector<int> A;
    int b;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto C = mul(A, b);

    if (C[C.size() - 1] == 0) cout << 0 << endl;

    else for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
}