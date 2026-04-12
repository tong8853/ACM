#include <bits/stdc++.h>
using namespace std;

struct node {
    array<int, 3> first;
    int has = 0;
    int bad = 0; // 是否出现过不同的三元组
};

void solve() {
    vector<int> a;
    int v;
    while (cin >> v) {
        if (v == -1) break;
        a.push_back(v);
    }
    a.push_back(0);
    a.push_back(0);
    unordered_map<int, int> mp1;      // 某个数出现次数
    unordered_map<int, node> node;    // 某个数对应的三元组情况
    vector<array<int, 3>> mp2;       // 按“第二次出现”的顺序记录候选三元组
    mp1.reserve(a.size() * 2);
    node.reserve(a.size() * 2);
    mp2.reserve(a.size());
    for (int i = 0; i + 2 < (int)a.size(); ++i) {
        array<int, 3> val = {a[i], a[i + 1], a[i + 2]};
        int x = a[i];
        if (mp1[x] == 1) {
            mp2.push_back(val);
        }
        ++mp1[x];
        auto &cur = node[x];
        if (!cur.has) {
            cur.has = true;
            cur.first = val;
        } else if (cur.first != val) {
            cur.bad = true;
        }
    }
    for (auto &val : mp2) {
        if (!node[val[0]].bad) {
            cout << val[0] << ' ' << val[1] << ' ' << val[2] << '\n';
            return;
        }
    }
    cout << "NONE\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}