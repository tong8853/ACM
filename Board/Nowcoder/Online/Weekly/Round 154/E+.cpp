#include <iostream>
#include <set>

using namespace std;

int n, k, x;
int a[202020];

multiset<int> lf;
multiset<int> rt;

void Insert(int x) {
    if (lf.empty() || x <= *lf.rbegin()) {
        lf.insert(x);
        if (lf.size() > rt.size() + 1) {
            rt.insert(rt.begin(), *lf.rbegin());
            lf.erase(prev(lf.end()));
        }
    }
    else {
        rt.insert(x);
        if (lf.size() < rt.size()) {
            lf.insert(lf.end(), *rt.begin());
            rt.erase(rt.begin());
        }
    }
}

void Erase(int x) {
    if (lf.size() && x <= *lf.rbegin()) {
        lf.erase(lf.find(x));
        if (lf.size() < rt.size()) {
            lf.insert(lf.end(), *rt.begin());
            rt.erase(rt.begin());
        }
    }
    else {
        rt.erase(rt.find(x));
        if (lf.size() > rt.size() + 1) {
            rt.insert(rt.begin(), *lf.rbegin());
            lf.erase(prev(lf.end()));
        }
    }
}

int Mid() {
    if (lf.empty()) {
        return 0;
    }
    if (lf.size() > rt.size()) {
        return *lf.rbegin();
    }
    int res = *lf.rbegin() + *rt.begin();
    if (res & 1) {
        return 0;
    }
    return res >> 1;
}

void Solve() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = k; i < n; i++) {
        Insert(a[i]);
    }
    int res = 0;
    if (Mid() == x) {
        res++;
    }
    for (int i = k; i < n; i++) {
        Erase(a[i]);
        Insert(a[i - k]);
        if (Mid() == x) {
            res++;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
}